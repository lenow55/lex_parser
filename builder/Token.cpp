#include "Token.h"
#include <cstddef>


const char* TokenTypeNames [] = {
    "IDENTIFIER",
    "KEYWORD",
    "NUMBER",
    "STRING",
    "OPERATOR",
    "DELIMITER",
    "COMPARE",
    "ERROR",
    "NOTYPE"};

TokenType Token::getTokenType() const {
    return this->token_type_;
}

const string &Token::getTokenValue() const {
    return this->token_value_;
}

size_t Token::getline() const {
    return this->line_number_;
}

size_t Token::getcolumn() const {
    return this->column_number_;
}

std::ostream &operator<<(std::ostream &os, const Token &token_) {
    os << "<" << TokenTypeNames[token_.getTokenType()] << ", {"
        << token_.getTokenValue() << "}, "
        << token_.getline() << ", "
        << token_.getcolumn()
        << ">" << std::endl;
    return os;
}
