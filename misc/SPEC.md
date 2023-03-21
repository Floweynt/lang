# Language specifications

## Tokens 
Tokens are defined as follow:  
```
match_id = [a-zA-Z_][a-zA-Z0-9_]*

TOK_IDENTIFIER := match_id
TOK_LANG_IDENTIFIER := @match_id
TOK_INTEGER := [0-9]+ ([0-9]+match_id, but this is currently unsupported)
TOK_CHAR := '.'
TOK_STRING := ([^"\\]|\\.)*
TOK_OPERATOR :=
    "::"
    "++"
    "--"
    "."
    "+"
    "-"
    "!"
    "~"
    "*"
    "&"
    "/"
    "%"
    "<<"
    ">>"
    "<=>"
    "<"
    "<="
    ">"
    ">="
    "=="
    "!="
    "^"
    "|"
    "&&"
    "||"
    "="
    "+="
    "-="
    "*="
    "/="
    "%="
    "<<="
    ">>="
    "&="
    "^="
    "|="
    "->"

TOK_PAREN_OPEN = '('
TOK_PAREN_OPEN := '('
TOK_PAREN_CLOSE := ')'
TOK_BRACKET_OPEN := '['
TOK_BRACKET_CLOSE := ']'
TOK_BRACE_OPEN := '{'
TOK_BRACE_CLOSE := '}'
TOK_SEMICOLON := ';'
TOK_COLON := ':'
TOK_COMMA := ','
TOK_BKSLASH := '\\'
TOK_ELLIPSIS := "..."

TOK_KW_AUTO := "auto"
TOK_KW_VAR := "const"
TOK_KW_VAR := "var"
TOK_KW_CONSTEVAL := "consteval"
TOK_KW_COMPTIME := "comptime"
TOK_KW_USING := "using"
TOK_KW_NAMESPACE := "namespace"
TOK_KW_YIELD := "yield"
TOK_KW_MATCH := "match"
TOK_KW_CASE := "case"
TOK_KW_IF := "if"
TOK_KW_ELSE := "else"
TOK_KW_WHILE := "while"
TOK_KW_FOR := "for"
TOK_KW_STRUCT := "struct"
```

## Syntax
The body of any file compiled should consist of a (maybe empty) list of `top-level-stmt`  
The following are the syntax definitions
```
top-level-stmt ::= variable-def-expr | using-expr | namespace-stmt
binary-op-expr ::= [ unary-expr (operator) ]
block-expr ::= [ expr ';' ] // (note that the semicolon is optional on some expressions, such as if) 
char-literal ::= TOK_CHAR
expr ::= variable-def-expr | using-expr | if-expr | binary-expr
identifier-expr ::= TOK_IDENTIFIER
if-expr ::= if ( expr ) expr ';' [ else if ( expr ) expr ] <else expr>
lambda-expr ::= TOK_BKSLASH ( variable-def-expr ) <TOK_OPERATOR(->) type-expr > block-expr
lang-id-expr ::= TOK_LANG_IDENTIFIER
namespace-stmt ::= TOK_KW_NAMESPACE TOK_IDENTIFIER [ '::' TOK_IDENTIFIER ] block-expr
paren-expr ::= ( expr )
simple-primary-expr ::= identifier-expr | lang-id-expr | TOK_INTEGER | TOK_FLOATING 
    | TOK_STRING | TOK_CHAR | paren-expr | lambda-expr
primary-expr ::= simple-primary-expr [ expr ] | ( expr )
struct-literal ::= tok_kw_struct { [variable-def-expr] }
type-expr ::= TOK_KW_AUTO | expr
unary-expr ::= unary-operator primary-expr
using-expr ::= TOK_KW_USING TOK_IDENTIFIER = expr
variable-expr ::= [ modifiers: consteval, comptime, const, var ] TOK_IDENTIFIER <TOK_ELLIPSIS> : type-expr < = expr > 
```

### Examples
Declare a variable:
```
var i: auto = 1;
var i: std::int = 2;
const i: auto = 1.2;
```
Declare a type:
```
comptime const Int = std::int;
using Float = std::Float
```

## Semantics
Most things have a value
