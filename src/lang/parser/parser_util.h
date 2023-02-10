#pragma once

#define report_error_range_msg(lexer, err, fix)                                                                                                      \
    do                                                                                                                                               \
    {                                                                                                                                                \
        ctx.report_error(lexer.curr_token().location(), lexer.curr_token().end_location(), err, fix);                                                \
        return nullptr;                                                                                                                              \
    } while (0);

#define report_error_point_msg(lexer, err, fix)                                                                                                      \
    do                                                                                                                                               \
    {                                                                                                                                                \
        ctx.report_error(lexer.curr_token().location(), err, fix);                                                                                   \
        return nullptr;                                                                                                                              \
    } while (0);

#define report_error_range(lexer, err)                                                                                                               \
    do                                                                                                                                               \
    {                                                                                                                                                \
        ctx.report_error(lexer.curr_token().location(), lexer.curr_token().end_location(), err);                                                     \
        return nullptr;                                                                                                                              \
    } while (0);

#define report_error_point(lexer, err)                                                                                                               \
    do                                                                                                                                               \
    {                                                                                                                                                \
        ctx.report_error(lexer.curr_token().location(), err);                                                                                        \
        return nullptr;                                                                                                                              \
    } while (0);

#define report_error_range_msg_pass(lexer, err, fix)                                                                                                 \
    do                                                                                                                                               \
    {                                                                                                                                                \
        ctx.report_error(lexer.curr_token().location(), lexer.curr_token().end_location(), err, fix);                                                \
        curr_parse_err = true;                                                                                                                       \
    } while (0);

#define report_error_point_msg_pass(lexer, err, fix)                                                                                                 \
    do                                                                                                                                               \
    {                                                                                                                                                \
        ctx.report_error(lexer.curr_token().location(), err, fix);                                                                                   \
        curr_parse_err = true;                                                                                                                       \
    } while (0);

#define report_error_range_pass(lexer, err)                                                                                                          \
    do                                                                                                                                               \
    {                                                                                                                                                \
        ctx.report_error(lexer.curr_token().location(), lexer.curr_token().end_location(), err);                                                     \
        curr_parse_err = true;                                                                                                                       \
    } while (0);

#define report_error_point_pass(lexer, err)                                                                                                          \
    do                                                                                                                                               \
    {                                                                                                                                                \
        ctx.report_error(lexer.curr_token().location(), err);                                                                                        \
        curr_parse_err = true;                                                                                                                       \
    } while (0);

#define curr_token_loc(lexer) lexer.curr_token().location(), lexer.curr_token().end_location()
