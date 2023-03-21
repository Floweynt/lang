#include <bitset>
#include <cinttypes>
#include <fmt/ranges.h>
#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <span>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

inline static constexpr auto BYTE_SIZE = 256;

class nfa_builder;

namespace detail
{
    class character_set
    {
    public:
        [[nodiscard]] virtual auto test(char ch) const -> bool = 0;
        virtual ~character_set() = default;
    };

    class regex_element
    {
    public:
        virtual auto generate(nfa_builder& builder, int64_t& node_alloc) const -> std::pair<int64_t, int64_t> = 0;
        virtual ~regex_element() = default;
    };
} // namespace detail

using char_set = std::shared_ptr<detail::character_set>;
using regex = std::shared_ptr<detail::regex_element>;

class dfa
{
    friend class nfa_builder;
    friend auto make_lexer(const std::vector<std::pair<regex, std::string>>& table) -> dfa;

    std::vector<int64_t> transition_table;
    int64_t start_state{};
    std::vector<bool> end_bitmask;
    std::vector<int64_t> end_to_nfa_state;
    std::unordered_map<int64_t, std::string> handler_map;

    dfa(int64_t states) : transition_table(states * BYTE_SIZE, -1), end_bitmask(states), end_to_nfa_state(states, -1) {}

public:
    void simulate(const std::string_view& buffer, auto callback) const;
    void codegen(std::ostream& out, std::string inc, std::string handle_eof, std::string handle_error, std::string handle_internal_error) const;
    void dump(std::ostream& ofs);
};

class nfa_builder
{
    struct entry
    {
        int64_t from, to;
        char ch;
    };

    std::vector<entry> edges;
    std::vector<std::pair<int64_t, int64_t>> epsilon_edges;
    std::vector<int64_t> start;
    std::vector<int64_t> end;
    int64_t max_val = 0;

public:
    constexpr nfa_builder() = default;

    template <std::convertible_to<char>... Args>
        requires(sizeof...(Args) > 1)
    constexpr auto transition(int64_t source, int64_t target, Args&&... val) -> nfa_builder&
    {
        return transition(source, target, {((char)val)...});
    }

    constexpr auto transition(int64_t source, int64_t target, const std::vector<char>& transition_list) -> nfa_builder&
    {
        for (auto transition_ch : transition_list)
        {
            transition(source, target, transition_ch);
        }
        return *this;
    }

    constexpr auto transition(int64_t from, int64_t end, char ch) -> nfa_builder&
    {
        max_val = std::max(std::max(max_val, from), end);
        edges.push_back({from, end, ch});
        return *this;
    }

    constexpr auto epsilon(int64_t from, int64_t end) -> nfa_builder&
    {
        max_val = std::max(std::max(max_val, from), end);
        epsilon_edges.emplace_back(from, end);
        return *this;
    }

    constexpr auto add_start(int64_t name) -> nfa_builder&
    {
        max_val = std::max(max_val, name);
        start.push_back(name);
        return *this;
    }

    constexpr auto add_end(int64_t name) -> nfa_builder&
    {
        max_val = std::max(max_val, name);
        end.push_back(name);
        return *this;
    }

    auto build() -> dfa;
};

class regex_parser
{
public:
    regex_parser(std::string regex) : curr_regex(std::move(regex)) {}
    auto parse() -> regex;
    void dump_error();

    [[nodiscard]] constexpr auto has_errors() const { return !errors.empty(); }

private:
    [[nodiscard]] auto peek() const -> char;
    [[nodiscard]] auto eof() const -> bool;
    auto match(char ch) -> bool;
    auto parse_char() -> regex;
    auto parse_atom() -> regex;
    auto parse_class() -> regex;
    auto parse_capture() -> regex;
    auto parse_escape() -> std::string;
    auto next() -> char;
    auto parse_quantifier() -> regex;
    auto parse_concat() -> regex;
    auto parse_alt() -> regex;
    auto parse_name() -> std::string;

    auto parse_char_class(const std::string& str, bool negate) -> regex;
    void error(std::string msg);

    const std::string curr_regex;
    std::vector<std::string> errors;
    size_t curr_pos{};
};

auto character(char ch) -> char_set
{
    class character : public detail::character_set
    {
        char ch;

    public:
        character(char ch) : ch(ch) {}
        [[nodiscard]] auto test(char ch) const -> bool override { return ch == this->ch; }
        ~character() override = default;
    };

    return std::make_shared<character>(ch);
}

auto character_range(char ch_from, char ch_to) -> char_set
{
    class character_range : public detail::character_set
    {
        char from;
        char to;

    public:
        character_range(char ch_from, char ch_to) : from(ch_from), to(ch_to) {}
        [[nodiscard]] auto test(char ch) const -> bool override { return from <= ch && ch <= to; }
        ~character_range() override = default;
    };

    return std::make_shared<character_range>(ch_from, ch_to);
}

template <int (*F)(int)>
auto wrap_predicate() -> const char_set&
{
    class wrap_libc : public detail::character_set
    {
    public:
        [[nodiscard]] auto test(char ch) const -> bool override { return F(ch); }
        ~wrap_libc() override = default;
    };

    static char_set instance = std::make_shared<wrap_libc>();
    return instance;
}

auto digit() -> const char_set& { return wrap_predicate<std::isdigit>(); }

auto alphanumeric() -> const char_set&
{
    return wrap_predicate<+[](int ch) -> int { return static_cast<int>(ch == '_' || (std::isalnum(ch) != 0)); }>();
}

auto whitespace() -> const char_set& { return wrap_predicate<std::isspace>(); }

auto empty() -> const char_set&
{
    return wrap_predicate<+[](int) -> int { return 0; }>();
}

auto xdigit() -> const char_set& { return wrap_predicate<isxdigit>(); }

auto operator&&(const char_set& lhs, const char_set& rhs) -> char_set
{
    class character_and : public detail::character_set
    {
        char_set lhs, rhs;

    public:
        character_and(char_set lhs, char_set rhs) : lhs(std::move(lhs)), rhs(std::move(rhs)) {}
        [[nodiscard]] auto test(char ch) const -> bool override { return rhs->test(ch) && lhs->test(ch); }
        ~character_and() override = default;
    };
    return std::make_shared<character_and>(lhs, rhs);
}

auto operator||(const char_set& lhs, const char_set& rhs) -> char_set
{
    class character_or : public detail::character_set
    {
        char_set lhs, rhs;

    public:
        character_or(char_set lhs, char_set rhs) : lhs(std::move(lhs)), rhs(std::move(rhs)) {}
        [[nodiscard]] auto test(char ch) const -> bool override { return rhs->test(ch) || lhs->test(ch); }
        ~character_or() override = default;
    };
    return std::make_shared<character_or>(lhs, rhs);
}

auto operator!(const char_set& lhs) -> char_set
{
    class character_not : public detail::character_set
    {
        char_set set;

    public:
        character_not(char_set set) : set(std::move(set)) {}
        [[nodiscard]] auto test(char ch) const -> bool override { return !set->test(ch); }
        ~character_not() override = default;
    };
    return std::make_shared<character_not>(lhs);
}

auto char_regex(const char_set& charset) -> regex
{
    struct ch_regex : public detail::regex_element
    {
        std::bitset<BYTE_SIZE> charset;

        auto generate(nfa_builder& builder, int64_t& node_alloc) const -> std::pair<int64_t, int64_t> override
        {
            auto start = node_alloc++;
            auto end = node_alloc++;

            for (int64_t i = 0; i < BYTE_SIZE; i++)
            {
                if (charset.test(i))
                {
                    builder.transition(start, end, (char)i);
                }
            }

            return {start, end};
        }
    };

    auto regexp = std::make_shared<ch_regex>();
    for (int64_t i = 0; i < BYTE_SIZE; i++)
    {
        regexp->charset.set(i, charset->test((char)i));
    }
    return regexp;
}

auto string_regex(const std::string& str) -> regex
{
    struct str_regex : public detail::regex_element
    {
        std::string str;
        str_regex(std::string str) : str(std::move(str)) {}

        auto generate(nfa_builder& builder, int64_t& node_alloc) const -> std::pair<int64_t, int64_t> override
        {
            auto start = node_alloc++;
            int64_t curr_target_node = start;

            for (auto ch : str)
            {
                auto tmp = node_alloc++;

                builder.transition(curr_target_node, tmp, ch);
                curr_target_node = tmp;
            }

            return {start, curr_target_node};
        }
    };

    return std::make_shared<str_regex>(str);
}

auto star_regex(const regex& regexp) -> regex
{
    struct star_regex : public detail::regex_element
    {
        regex regexp;
        star_regex(regex regexp) : regexp(std::move(regexp)) {}

    protected:
        auto generate(nfa_builder& builder, int64_t& node_alloc) const -> std::pair<int64_t, int64_t> override
        {
            auto [start, end] = regexp->generate(builder, node_alloc);
            builder.epsilon(start, end);
            builder.epsilon(end, start);
            return {start, end};
        }
    };

    return std::make_shared<star_regex>(regexp);
};

auto operator+(const regex& lhs, const regex& rhs) -> regex
{
    struct plus_regex : public detail::regex_element
    {
        regex rhs, lhs;
        plus_regex(regex rhs, regex lhs) : rhs(std::move(rhs)), lhs(std::move(lhs)) {}

        auto generate(nfa_builder& builder, int64_t& node_alloc) const -> std::pair<int64_t, int64_t> override
        {
            auto [rs, re] = rhs->generate(builder, node_alloc);
            auto [ls, le] = lhs->generate(builder, node_alloc);
            builder.epsilon(re, ls);
            return {rs, le};
        }
    };

    return std::make_shared<plus_regex>(lhs, rhs);
}

auto plus_regex(const regex& regexp) -> regex { return regexp + star_regex(regexp); }

auto optional_regex(const regex& regexp) -> regex
{
    struct opt_regex : public detail::regex_element
    {
        regex regexp;
        opt_regex(regex regexp) : regexp(std::move(regexp)) {}

        auto generate(nfa_builder& builder, int64_t& node_alloc) const -> std::pair<int64_t, int64_t> override
        {
            auto [start, end] = regexp->generate(builder, node_alloc);
            builder.epsilon(start, end);
            return {start, end};
        }
    };

    return std::make_shared<opt_regex>(regexp);
}

auto operator|(const regex& lhs, const regex& rhs) -> regex
{
    struct or_regex : public detail::regex_element
    {
        regex rhs, lhs;
        or_regex(regex rhs, regex lhs) : rhs(std::move(rhs)), lhs(std::move(lhs)) {}

        auto generate(nfa_builder& builder, int64_t& node_alloc) const -> std::pair<int64_t, int64_t> override
        {
            auto start = node_alloc++;
            auto end = node_alloc++;

            auto [ls, le] = lhs->generate(builder, node_alloc);
            auto [rs, re] = rhs->generate(builder, node_alloc);

            builder.epsilon(start, ls);
            builder.epsilon(start, rs);

            builder.epsilon(le, end);
            builder.epsilon(re, end);

            return {start, end};
        }
    };

    return std::make_shared<or_regex>(lhs, rhs);
}

auto char_regex(char ch) -> regex { return char_regex(character(ch)); }
auto dot_regex() -> regex { return char_regex(!empty()); }

// This will calculate the set of states that can be reached from e with only epsilon moves
auto build_epsilon_closure_from(const std::vector<std::unordered_set<int64_t>>& epsilon, int64_t node, std::vector<bool>& bitmask)
    -> std::vector<bool>&
{
    std::queue<int64_t> to_process;
    to_process.push(node);
    while (!to_process.empty())
    {
        int64_t curr = to_process.front();
        to_process.pop();
        bitmask[curr] = true;
        for (auto ch : epsilon[curr])
        {
            if (!bitmask[ch])
            {
                to_process.push(ch);
            }
        }
    }
    return bitmask;
}

auto nfa_builder::build() -> dfa
{
    const int64_t nodes = max_val + 1;

    std::list<entry> output_edges;
    std::unordered_map<std::vector<bool>, int64_t> subset_to_id;
    int64_t curr_node_id = 0;
    std::vector<std::unordered_set<int64_t>> transition_table(nodes * BYTE_SIZE);
    std::vector<std::unordered_set<int64_t>> epsilon_table(nodes);
    std::vector<bool> start_bitset(nodes);
    std::vector<bool> tmp_state_set(nodes);
    std::queue<std::vector<bool>> nodes_to_process;

    for (const auto& edge : epsilon_edges)
    {
        epsilon_table[edge.first].insert(edge.second);
    }
    for (auto node : start)
    {
        build_epsilon_closure_from(epsilon_table, node, start_bitset);
    }
    for (const auto& edge : edges)
    {
        transition_table[edge.from * BYTE_SIZE + (int64_t)edge.ch].insert(edge.to);
    }

    nodes_to_process.push(start_bitset);
    subset_to_id[start_bitset] = curr_node_id++;

    while (!nodes_to_process.empty())
    {
        auto node = nodes_to_process.front();
        nodes_to_process.pop();
        for (int64_t ch = 0; ch < BYTE_SIZE; ch++)
        {
            bool is_not_empty = false;
            for (int64_t i = 0; i < nodes; i++)
            {
                if (!node[i])
                {
                    continue;
                }
                for (auto target : transition_table[i * BYTE_SIZE + ch])
                {
                    is_not_empty = true;
                    build_epsilon_closure_from(epsilon_table, target, tmp_state_set);
                }
            }

            if (is_not_empty)
            {
                if (!subset_to_id.contains(tmp_state_set))
                {
                    nodes_to_process.push(tmp_state_set);
                    subset_to_id[tmp_state_set] = curr_node_id++;
                }

                int64_t node_from = subset_to_id[node];
                int64_t node_to = subset_to_id[tmp_state_set];
                output_edges.push_back({node_from, node_to, (char)ch});
                tmp_state_set.assign(nodes, false);
            }
        }
    }

    dfa ret(curr_node_id);
    ret.start_state = 0;

    std::unordered_map<int64_t, std::vector<bool>> vec;

    for (const auto& entry : subset_to_id)
    {
        vec[entry.second] = entry.first;
    }

    for (const auto& entry : subset_to_id)
    {
        for (const auto& nfa_node_id : end)
        {
            // if this state contains an end node...
            if (entry.first[nfa_node_id])
            {
                ret.end_bitmask[entry.second] = true;
                // we store the end state type from the NFA
                ret.end_to_nfa_state[entry.second] = nfa_node_id;
            }
        }
    }

    for (const auto& edge : output_edges)
    {
        ret.transition_table[edge.from * BYTE_SIZE + (int64_t)edge.ch] = edge.to;
    }

    return ret;
}

auto make_lexer(const std::vector<std::pair<regex, std::string>>& table) -> dfa
{
    nfa_builder nfa;
    int64_t node_alloc = 0;
    int64_t start = node_alloc++;
    std::unordered_map<int64_t, std::string> handler_map;

    for (const auto& entry : table)
    {
        auto [s, e] = entry.first->generate(nfa, node_alloc);
        nfa.epsilon(start, s);
        nfa.add_end(e);
        handler_map[e] = entry.second;
    }

    nfa.add_start(start);
    auto dfa = nfa.build();
    dfa.handler_map = std::move(handler_map);
    return dfa;
}

void dfa::simulate(const std::string_view& buffer, auto callback) const
{
    int64_t state = start_state;
    int64_t latest_match = -1;
    std::string match_buf;

    for (int64_t index = 0; index < buffer.size(); index++)
    {
        state = transition_table[state * BYTE_SIZE + (int64_t)buffer[index]];

        if (state == -1)
        {
            if (latest_match == -1)
            {
                break;
            }
            callback(latest_match, match_buf);

            // reset the state machine so we can process more information
            latest_match = -1;
            index--;
            state = start_state;
            match_buf.clear();
            continue;
        }

        if (end_bitmask[state])
        {
            latest_match = state;
        }
        match_buf += buffer[index];
    }
}

inline constexpr auto FMT_CODEGEN = R"(
#include <deque>
#include <istream>
#include <vector>
#include <cstdint>
#include <string>
#include <iostream>

{}

// transition state tables
inline static constexpr int64_t TRANSITION_TABLE[] = {{ {} }};
inline static constexpr int64_t START_STATE = {};
inline static constexpr bool END_BITMASK[] = {{ {} }};
inline static constexpr int64_t END_TO_NFA_STATE[] = {{ {} }};

static char peek(lex_context& ctx)
{{
    if (ctx.peek_index < ctx.buffer.size())
        return ctx.buffer[ctx.peek_index++];
    char ch = 0;
    ctx.in.get(ch);

    ctx.pbytes++;
    ctx.pcol++;
    if(ch == '\n')
    {{
        ctx.pline++;
        ctx.pcol = 1;
    }}

    ctx.buffer.push_back(ch);
    ctx.peek_index++;
    return ch;
}}

static void reset(lex_context& ctx)
{{
    ctx.peek_index = 0;
    /*ctx.pbytes = ctx.bytes;
    ctx.pcol = ctx.col;
    ctx.pline = ctx.line;*/
}}

static void seek_up(lex_context& ctx)
{{
    ctx.buffer.erase(ctx.buffer.begin(), ctx.buffer.begin() + ctx.peek_index);
    ctx.peek_index = 0;
    ctx.bytes = ctx.pbytes;
    ctx.col = ctx.pcol;
    ctx.line = ctx.pline;
}}

template <typename C>
static void commit_to_buffer(C& output, lex_context& ctx)
{{
    output.insert(output.end(), ctx.buffer.begin(), ctx.buffer.begin() + ctx.peek_index);
    seek_up(ctx);
}}

auto lex_tok(lex_context& ctx)
{{
    if(ctx.in.eof())
    {{ 
        {} 
    }}

    int64_t state = START_STATE;
    int64_t latest_match = -1;
    std::string buffer;

    size_t start_line = ctx.line;
    size_t start_col = ctx.col;
    size_t start_bytes = ctx.bytes;

    while (true)
    {{
        state = TRANSITION_TABLE[state * 256 + peek(ctx)];
        if (state != -1 && END_BITMASK[state])
        {{
            latest_match = state;
            commit_to_buffer(buffer, ctx);
        }}

        if (state == -1 || ctx.in.eof())
        {{
            if (latest_match == -1)
            {{
                // report error
                {}
            }}

            reset(ctx);
            switch(END_TO_NFA_STATE[latest_match])
            {{
            {}
            default:
                {}
            }}

            latest_match = -1;
            state = START_STATE;
            buffer.clear();

            start_line = ctx.line;
            start_col = ctx.col;
            start_bytes = ctx.bytes;
            
            if(ctx.in.eof())
            {{ 
                {} 
            }}

            continue;
        }}
    }}
}})";

void dfa::codegen(std::ostream& out, std::string inc, std::string handle_eof, std::string handle_error, std::string handle_internal_error) const
{
    std::string switch_str;
    for (const auto& handler : handler_map)
    {
        switch_str += fmt::format(R"(case {}: {})", handler.first, handler.second);
    }

    out << fmt::format(FMT_CODEGEN, inc, fmt::join(transition_table, ","), start_state, fmt::join(end_bitmask, ","), fmt::join(end_to_nfa_state, ","),
                       handle_eof, handle_error, switch_str, handle_internal_error, handle_eof);
}

static auto proc(char ch) -> std::string
{
    if (!isprint(ch))
    {
        return fmt::format("\\\\x{:02x}", (unsigned char)ch);
    }
    if (ch == '"')
    {
        return "\\\"";
    }
    if (ch == '\\')
    {
        return "\\\\";
    }
    return std::string(1, ch);
}

void dfa::dump(std::ostream& ofs)
{
    for (size_t i = 0; i < end_bitmask.size(); i++)
    {
        std::unordered_set<size_t> set;

        for (size_t ch = 0; ch < BYTE_SIZE; ch++)
        {
            if (transition_table[i * BYTE_SIZE + ch] != -1UL)
            {
                set.insert(transition_table[i * BYTE_SIZE + ch]);
            }
        }

        for (auto entry : set)
        {
            std::string out;

            for (size_t ch = 0; ch < BYTE_SIZE; ch++)
            {
                size_t start_ch = ch;
                while (transition_table[i * BYTE_SIZE + ch] == entry && ch < BYTE_SIZE)
                {
                    ch++;
                }
                size_t end_ch = ch;
                if (start_ch == end_ch)
                {
                    continue;
                }

                if (start_ch + 1 == end_ch)
                {
                    out += proc((char)start_ch);
                }
                else
                {
                    out += fmt::format("[{}-{}]", proc((char)start_ch), proc((char)(end_ch - 1)));
                }
            }

            ofs << fmt::format("{} -> {} [label=\"{}\"]\n", i, entry, out);
        }

        if (end_bitmask[i])
        {
            ofs << fmt::format("{} [shape=box]\n", i);
        }
    }
}

void regex_parser::error(std::string msg) { errors.push_back(msg); }

auto regex_parser::peek() const -> char { return curr_pos < curr_regex.size() ? curr_regex[curr_pos] : '\0'; }

auto regex_parser::eof() const -> bool { return curr_pos >= curr_regex.size(); }

auto regex_parser::match(char ch) -> bool
{
    if (peek() == ch)
    {
        ++curr_pos;
        return true;
    }
    return false;
}

auto regex_parser::parse_char() -> regex
{
    if (peek() == '\\')
    {
        match('\\');
        char ch = peek();

        if (ch == 'n')
        {
            next();
            return char_regex('\n');
        }
        if (ch == '\\')
        {
            next();
            return char_regex('\\');
        }

        if (ch == 'w' || ch == 'd' || ch == 's' || ch == 'W' || ch == 'D' || ch == 'S')
        {
            match(ch);
            switch (ch)
            {
            case 'w':
                return char_regex(alphanumeric());
            case 'W':
                return char_regex(!alphanumeric());
            case 'd':
                return char_regex(digit());
            case 'D':
                return char_regex(!digit());
            case 's':
                return char_regex(whitespace());
            case 'S':
                return char_regex(!whitespace());
            }
        }
        else
        {
            match(ch);
            return char_regex(ch);
        }
    }
    else
    {
        char ch = peek();
        if (ch != '|' && ch != ')' && ch != '*' && ch != '+' && ch != '?')
        {
            ++curr_pos;
            return char_regex(ch);
        }
    }
    return nullptr;
}

auto regex_parser::parse_char_class(const std::string& str, bool negate) -> regex
{
    auto current_charset = empty();
    for (size_t i = 0; i < str.size(); i++)
    {
        if (i + 1 < str.size() && str[i + 1] == '-')
        {
            if (i + 2 == str.size())
            {
                current_charset = current_charset || character(str[i + 1]);
                i++;
                break;
            }

            current_charset = current_charset || character_range(str[i], str[i + 2]);
            i += 2;
        }
        else
        {
            current_charset = current_charset || character(str[i]);
        }
    }

    return char_regex(negate ? !current_charset : current_charset);
}

// Parse an atom (character or capture group)
auto regex_parser::parse_atom() -> regex
{
    if (match('['))
    {
        std::string chars;
        bool negate = false;
        if (match('^'))
        {
            negate = true;
        }
        while (!match(']'))
        {
            if (eof())
            {
                error("unterminated character set");
                return nullptr;
            }
            if (match('\\'))
            {
                chars += parse_escape();
            }
            else
            {
                chars += next();
            }
        }

        return parse_char_class(chars, negate);
    }
    else if (match('('))
    {
        auto expr = parse_alt();
        if (match(')'))
        {
            return expr;
        }
        return nullptr;
    }
    else if (match('.'))
    {
        return char_regex(!empty());
    }

    return parse_char();
}

auto regex_parser::next() -> char
{
    if (!eof())
    {
        return curr_regex[curr_pos++];
    }

    return '\0';
}

auto regex_parser::parse_escape() -> std::string
{
    char ch = peek();

    if (ch == 'n')
    {
        next();
        return "\n";
    }

    if (ch == '\\')
    {
        next();
        return "\\";
    }

    if (ch == 'x')
    {
        next();
        std::string hex;
        for (int i = 0; i < 2; ++i)
        {
            char digit = next();
            if (!isxdigit(digit))
            {
                error("invalid hexadecimal escape");
                return "";
            }
            hex += digit;
        }
        return hex;
    }

    if (isdigit(ch))
    {
        std::string oct;
        for (int i = 0; i < 3; ++i)
        {
            char digit = peek();
            if (!isdigit(digit))
            {
                break;
            }
            oct += next();
        }
        return oct;
    }

    next();
    return std::string(1, ch);
}

// Parse a character class (\w, \d, \s, etc.)
auto regex_parser::parse_class() -> regex
{
    if (match('\\'))
    {
        char ch = peek();
        if (ch == 'w' || ch == 'd' || ch == 's' || ch == 'W' || ch == 'D' || ch == 'S')
        {
            match(ch);
            switch (ch)
            {
            case 'w':
                return char_regex(alphanumeric());
            case 'W':
                return char_regex(!alphanumeric());
            case 'd':
                return char_regex(digit());
            case 'D':
                return char_regex(!digit());
            case 's':
                return char_regex(whitespace());
            case 'S':
                return char_regex(!whitespace());
            }
        }
    }
    return nullptr;
}

auto regex_parser::parse_capture() -> regex
{
    if (match('('))
    {
        regex expr = parse_alt();
        if (match(')'))
        {
            return expr;
        }
        return nullptr;
    }
    return nullptr;
}

auto regex_parser::parse_quantifier() -> regex
{
    regex atom = parse_atom();
    if (atom)
    {
        if (match('*'))
        {
            return star_regex(atom);
        }
        if (match('+'))
        {
            return plus_regex(atom);
        }
        if (match('?'))
        {
            return optional_regex(atom);
        }
        return atom;
    }
    return nullptr;
}

auto regex_parser::parse_concat() -> regex
{
    regex left = parse_quantifier();
    if (left)
    {
        while (!eof())
        {
            regex right = parse_quantifier();
            if (right)
            {
                left = left + right;
            }
            else
            {
                break;
            }
        }
    }
    return left;
}

auto regex_parser::parse_alt() -> regex
{
    regex left = parse_concat();
    if (left)
    {
        while (match('|'))
        {
            regex right = parse_concat();
            if (right)
            {
                left = left | right;
            }
            else
            {
                break;
            }
        }
    }
    return left;
}

auto regex_parser::parse_name() -> std::string
{
    std::string name;
    while (!eof())
    {
        char ch = peek();
        if (isalnum(ch) || ch == '_')
        {
            name += ch;
            ++curr_pos;
        }
        else
        {
            break;
        }
    }
    return name;
}

auto regex_parser::parse() -> regex
{
    regex root = parse_alt();
    if (!eof())
    {
        return nullptr;
    }
    return root;
}

void regex_parser::dump_error()
{
    for (const auto& error : errors)
    {
        std::cerr << error << '\n';
    }
}

// driver code

struct option
{
    std::string_view name;
    std::string_view long_flag;
    std::string_view short_flag;
    std::string_view description;
    bool has_args;
    bool required;
};

struct argument_value
{
    bool present;
    const char* value;
};

struct arg_spec
{
    std::span<const option> options;
    std::string_view program_name;
    std::string_view version;
};

struct arg_data
{
    std::vector<std::string> input_values;
    std::unordered_map<std::string, argument_value> values;
};

inline static constexpr option options[] = {
    {"dot-out", "--emit-dot", "-D", "specifies the output for the dot file for DFA graph visualization", true, false},
    {"cpp-out", "--output", "-o", "specifies the output source file", true, true}};

void make_help_msg(const arg_spec& options)
{
    std::cerr << "usage: " << options.program_name << " [files] [flags]" << '\n';
    for (const auto& opt : options.options)
    {
        std::cerr << fmt::format("    {: <10} {: <10}: {}\n", opt.short_flag, opt.long_flag, opt.description);
    }
}

using namespace std::string_literals;
auto parse_args(const std::span<const char*> args, const arg_spec& options)
{
    std::unordered_map<std::string, argument_value> values;

    bool is_await_args = false;
    std::string await_args_name;
    std::vector<std::string> input_values;

    for (const auto* arg : args)
    {
        if (is_await_args)
        {
            values[await_args_name].value = arg;
            is_await_args = false;
            continue;
        }

        if (arg == "--help"s)
        {
            make_help_msg(options);
            exit(0);
        }

        if (arg == "--version"s)
        {
            std::cerr << options.program_name << ": " << options.version << '\n';
            exit(0);
        }

        if (!std::string_view(arg).starts_with("-"))
        {
            input_values.emplace_back(arg);
            continue;
        }

        bool found = false;
        for (const auto& opt : options.options)
        {
            if (arg == opt.long_flag || arg == opt.short_flag)
            {
                values[await_args_name = opt.name].present = true;
                is_await_args = opt.has_args;
                found = true;
                break;
            }
        }

        if (!found)
        {
            std::cerr << "unknown option: " << arg << '\n';
            exit(-1);
        }
    }

    for (const auto& opt : options.options)
    {
        if (!values[std::string(opt.name)].present && opt.required)
        {
            std::cerr << "missing required option " << opt.long_flag << '\n';
            exit(-1);
        }
    }

    return arg_data{input_values, values};
}

auto handle_escape_str(const std::string& str) -> std::string
{
    std::string result;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '\\')
        {
            if (i + 1 >= str.length())
            {
                std::cerr << "invalid escape sequence at end of string\n";
                exit(-1);
            }
            switch (str[i + 1])
            {
            case 'n':
                result += '\n';
                break;
            case 't':
                result += '\t';
                break;
            case 'r':
                result += '\r';
                break;
            case '\'':
                result += '\'';
                break;
            case '\"':
                result += '\"';
                break;
            case '\\':
                result += '\\';
                break;
            case 'x': {
                if (i + 3 >= str.length())
                {
                    std::cerr << "incomplete hexadecimal escape sequence";
                    exit(-1);
                }
                char hex[3] = {str[i + 2], str[i + 3], '\0'};
                int value = std::stoi(hex, nullptr, 16);
                result += static_cast<char>(value);
                i += 3; // skip the next 3 characters (the \x and two hex digits)
                break;
            }
            case '0': {
                bool valid = false;
                int value = 0;
                for (int j = i + 1; j <= i + 3 && j < str.length(); j++)
                {
                    if (str[j] >= '0' && str[j] <= '7')
                    {
                        valid = true;
                        value = (value << 3) + (str[j] - '0');
                    }
                    else
                    {
                        break;
                    }
                }
                if (!valid)
                {
                    if (i + 1 == str.length() || (i + 2 < str.length() && str[i + 2] >= '0' && str[i + 2] <= '7'))
                    {
                        result += '\0';
                        i++; // skip the next character ('\0')
                    }
                    else
                    {
                        std::cerr << "incomplete or invalid octal escape sequence";
                        exit(-1);
                    }
                }
                else
                {
                    result += static_cast<char>(value);
                    i += 3; // skip the next 3 characters (the \0 and up to three octal digits)
                }
                break;
            }
            default: {
                result += str[i + 1]; // append the character
                break;
            }
            }
            i++;
        }
        else
        {
            result += str[i];
        }
    }

    return str;
}

auto main(int argc, const char* argv[]) -> int
{
    auto [files, args] = parse_args(std::span<const char*>(argv + 1, argc - 1), arg_spec{options, "lexer-gen", "v0.0.1"});

    if (files.size() != 1)
    {
        std::cerr << "expected only one input file\n";
        exit(-1);
    }

    std::ifstream in_file(files[0]);
    std::string init_buffer;
    std::string handle_eof;
    std::string handle_error;
    std::string handle_internal_error;
    std::vector<std::pair<regex, std::string>> tokens;

    std::string line;

    while (std::getline(in_file, line))
    {
        if (line.empty())
        {
            break;
        }
        init_buffer += line += '\n';
    }

    std::getline(in_file, handle_eof);
    std::getline(in_file, handle_error);
    std::getline(in_file, handle_internal_error);

    if (handle_eof.empty() || handle_error.empty() || handle_internal_error.empty())
    {
        std::cerr << "handlers must not be empty\n";
        exit(-1);
    }

    std::getline(in_file, line);

    if (!line.empty())
    {
        std::cerr << "expected empty line\n";
        exit(-1);
    }

    while (std::getline(in_file, line))
    {
        if (line.empty() || line.starts_with(";") || line.starts_with("#"))
        {
            continue;
        }

        auto index = line.find(" -> ");
        std::string pattern = line.substr(0, index);
        std::string handler = line.substr(index + 4);
        regex entry;

        if (pattern[0] == '"')
        {
            entry = string_regex(handle_escape_str(pattern.substr(1, pattern.size() - 2)));
        }
        else
        {
            regex_parser parser(pattern);
            entry = parser.parse();
            parser.dump_error();
            if (parser.has_errors())
            {
                exit(-1);
            }
        }

        tokens.emplace_back(entry, handler);
    }

    std::ofstream out(args["cpp-out"].value);
    if (!out)
    {
        std::cerr << "unable to open file: " << args["cpp-out"].value << '\n';
        exit(-1);
    }

    auto dfa = make_lexer(tokens);
    dfa.codegen(out, init_buffer, handle_eof, handle_error, handle_internal_error);

    if (args["dot-out"].present)
    {
        std::ofstream dot_out(args["dot-out"].value);
        if (!dot_out)
        {
            std::cerr << "unable to open file: " << args["dot-out"].value << '\n';
            exit(-1);
        }

        dot_out << "digraph G{";
        dfa.dump(dot_out);
        dot_out << "}";
    }
}
