/* Fig.: TokenBuilder
 * ======================================================
 * Filename: TokenBuilder.h
 * =====================================================
 * Abstract: Header модуль
 * лаборатоной лексическому анализатору
 * Description: парсит входной файл и выводит файл-таблицу
 * лексем
 * Author: Новиков Илья
 * Platform: Linux
 ==================================================== */
#pragma once

#include <cstddef>
#include <string>
#include "Token.h"

using std::string;
using std::size_t;

class TokenBuilder {
    protected:
        TokenType token_type_;
        string token_value_;
        size_t line_number_;
        size_t column_number_;

    public:
        TokenBuilder():
            token_type_(NOTYPE),
            token_value_(""),
            line_number_(0),
            column_number_(0) {}
        ~TokenBuilder() {};
        void setType(TokenType);
        void setPosition(size_t, size_t);
        void addValue(char);
        void clearValue();
        Token build();
};
