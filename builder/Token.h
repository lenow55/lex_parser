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

using std::string;
using std::size_t;

enum TokenType {
    IDENTIFIER,
    KEYWORD,
    NUMBER,
    STRING,
    OPERATOR,
    DELIMITER,
    COMMENT,
    COMPARE,
    NOTYPE //заглушка для создателя
};

class Token {
    private:
        TokenType token_type_;
        string token_value_;
        size_t line_number_;
        size_t column_number_;
    public:
        Token(TokenType token_type, const string& token_value,
                size_t line_number, size_t column_number):
            token_type_(token_type), token_value_(token_value),
            line_number_(line_number), column_number_(column_number) {}

};

std::ostream &operator<<(std::ostream &, const Token &);
