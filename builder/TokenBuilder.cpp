#include "TokenBuilder.h"
#include "Token.h"
#include <cstddef>

void TokenBuilder::setType(TokenType type) {
    this->token_type_ = type;
}

void TokenBuilder::setPosition(size_t line, size_t column) {
    this->line_number_ = line;
    this->column_number_ = column;
}

void TokenBuilder::addValue(char value) {
    this->token_value_.push_back(value);
}

void TokenBuilder::clearValue() {
    this->token_value_.clear();
}

Token TokenBuilder::build() {
    return Token(
            token_type_,
            token_value_,
            line_number_,
            column_number_
            );
}
