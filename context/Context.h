/**
 * Контекст определяет интерфейс, представляющий интерес для клиентов. Он также
 * хранит ссылку на экземпляр подкласса Состояния, который отображает текущее
 * состояние Контекста.
 */

#pragma once

#include "TokenBuilder.h"
#include <cstddef>
#include <fstream>
#include <memory>  // Добавлен заголовочный файл memory

using std::size_t;

class State;
class TokenBuilder;

class LexerContext {
    /**
     * @var State Ссылка на текущее состояние Контекста.
     */
    private:
        std::ifstream file;       // Файловый поток
        size_t line;                 // Текущий номер строки
        size_t column;               // Текущий номер колонки
        char currentChar;         // Текущий символ
        std::unique_ptr<State> currentState;      // Текущее состояние
        TokenBuilder *tokenBuilder;

    public:
        LexerContext() :
            currentState(nullptr),
            tokenBuilder(nullptr),
            line(0),
            column(0){}
        ~LexerContext() {
            delete tokenBuilder;
        }
        void TransitionTo(State *, const char *);
        void setState(std::unique_ptr<State>);
        void setTokenBuilder(TokenBuilder*);
        void initTokenBuilder();
        void createTokenBuilder();
        TokenBuilder *getTokenBuilder();
        State *getState() const;
        void processFile();
        void setState(State*);
        bool isEOF() const;
        size_t getColumn() const;
        size_t getLine() const;
        void moveToNextChar();
        void setFile(const string&);
};

