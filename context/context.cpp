#include "Context.h"
#include "A_state.h"
#include "Scope.h"
#include "StartState.h"
#include "TokenBuilder.h"
#include <iostream>
#include <stdexcept>
#include <string>

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
    return file.eof() && currentChar == '\0' || currentChar == -1;
}

void LexerContext::setState(State *newState) {
    currentState = std::move(std::unique_ptr<State>(newState));
}

State* LexerContext::getState() const {
    return currentState.get();
}

void LexerContext::processFile() {
    while (!isEOF()) {
        currentState->handle(currentChar, this);
        moveToNextChar();
    }
    std::cout << *(this->currentScope);
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
    this->tokenBuilder->setType(NOTYPE);
    this->tokenBuilder->clearValue();
}

TokenBuilder *LexerContext::getTokenBuilder() {
    return this->tokenBuilder;
}

void LexerContext::setFile(const string& filename) {
    try {
        file.open(filename);
    }
    catch (const std::ifstream::failure& e) {
        std::cout << "Exception opening/reading file";
        throw e;
    }
    if (!file.is_open()) {
        std::string errMsg =  "Failed to open file: " + filename;
        throw std::runtime_error(errMsg);
    } else {
        moveToNextChar();  // Переходим к первому символу при открытии файла
    }
}

void LexerContext::storeToken() {
    Token token = this->tokenBuilder->build();
    // std::cout << token;
}


void LexerContext::initState() {
    this->currentState = std::unique_ptr<State>(new StartState);
}

void LexerContext::closeFile() {
    file.close();
}

void LexerContext::increaseScope() {
    this->currentScope->increaseIndex();
    Scope *newScope = new Scope(
            this->currentScope,
            this->currentScope->getLevel() + 1,
            this->currentScope->getIndex());
}

void LexerContext::decreaseScope() {
    Scope *parent = this->currentScope->getParentScope();
    std::cout << *(this->currentScope);
    delete this->currentScope;
    this->currentScope = parent;
}
