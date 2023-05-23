#pragma once

#include <cstddef>
#include <string>
#include <ostream>

using std::string;
using std::size_t;

class Scope {
    private:
        Scope *parent_scope_;
        string token_value_;
        size_t line_number_;
        size_t column_number_;
    public:
        Scope(TokenType token_type, const string& token_value,
                size_t line_number, size_t column_number);
        TokenType getTokenType() const;
        const string &getTokenValue() const;
        size_t getline() const;
        size_t getcolumn() const;

};

std::ostream &operator<<(std::ostream &os, const Token &token_);
