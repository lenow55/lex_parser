/* Fig.: main
 * ======================================================
 * Filename: main.cpp
 * =====================================================
 * Abstract: Основной исполняемый модуль
 * лаборатоной лексическому анализатору
 * Description: парсит входной файл и выводит файл-таблицу
 * лексем
 * Author: Новиков Илья
 * Platform: Linux
 ==================================================== */

#include "A_state.h"

class CommentOperatorState : public State {
    public:
        ~CommentOperatorState() override {}
        virtual void handle(char, LexerContext*) override;
};

class CommentState : public State {
    public:
        ~CommentState() override {}
        virtual void handle(char, LexerContext*) override;
};

class CommentEndState : public State {
    public:
        ~CommentEndState() override {}
        virtual void handle(char, LexerContext*) override;
};
