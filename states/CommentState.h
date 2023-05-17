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

class CommentState : public State {
    public:
        ~CommentState() override {}
        virtual void handle(char, LexerContext*) override;
};

