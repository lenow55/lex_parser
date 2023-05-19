#include "Context.h"
#include "A_state.h"
#include "TokenBuilder.h"
#include <stdexcept>

void LexerContext::setTokenBuilder(TokenBuilder* token_builder) {
    if (this->tokenBuilder != nullptr)
        delete this->tokenBuilder;
    this->tokenBuilder = token_builder;
}

void LexerContext::initTokenBuilder() {
    if (this->tokenBuilder != nullptr)
        delete this->tokenBuilder;
    this->tokenBuilder = new TokenBuilder;
}

size_t LexerContext::getLine() const {
    return line;
}

size_t LexerContext::getColumn() const {
    return column;
}

bool LexerContext::isEOF() const {
    return file.eof() && currentChar == '\0';
}

void LexerContext::setState(std::unique_ptr<State> newState) {
    currentState = std::move(newState);
}

State* LexerContext::getState() const {
    return currentState.get();
}

void LexerContext::processFile() {
    while (!isEOF()) {
        currentState->handle(currentChar, this);
        moveToNextChar();
    }
}

void LexerContext::moveToNextChar() {
    if (file.good()) {
        if (currentChar == '\n') {
            line++;
            column = 0;
        }
        currentChar = file.get();
        column++;
    } else {
        currentChar = '\0';
    }
}

void LexerContext::clearTokenBuilder() {
    //this->tokenBuilder = new TokenBuilder;
    this->tokenBuilder->setPosition(this->line, this->column);
    this->tokenBuilder->clearValue();
}

TokenBuilder *LexerContext::getTokenBuilder() {
    return this->tokenBuilder;
}

void LexerContext::setFile(const string& filename) {
    file.open(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + filename);
    } else {
        moveToNextChar();  // Переходим к первому символу при открытии файла
    }
}
