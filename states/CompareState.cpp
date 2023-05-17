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

#include "StartState.h"
#include "CompareState.h"
#include "OperatorStates.h"
#include "KeywordStates.h"
#include "StringState.h"
#include "NumberState.h"
#include "IdentifierState.h"
#include "Token.h"
#include "TokenBuilder.h"
#include "Context.h"
#include <cctype>

void CompareState::handle(char simbol, LexerContext *context) {
    context->createTokenBuilder();
    context->getTokenBuilder()->addValue(simbol);
    switch (simbol) {
        case '\"':
            context->getTokenBuilder()->setType(STRING);
            context->setState(new StringState);
        case ';':
        case '(':
        case ')':
            context->getTokenBuilder()->setType(DELIMITER);
            context->setState(new DelimiterState);
        case ' ':
            context->getTokenBuilder()->build();
            context->setState(new StartState)
            break;
        case '_':
            context->getTokenBuilder()->setType(IDENTIFIER);
            context->setState(new IdentifierState);
        default:
            if (isdigit(simbol)) {
                context->getTokenBuilder()->setType(NUMBER);
                context->setState(new NumberState);
                return;
            }
            if (isalpha(simbol)) {
                context->getTokenBuilder()->setType(IDENTIFIER);
                context->setState(new IdentifierState);
                return;
            }
            throw::runtime_error("ERROR with this simbol: " + simbol);
            break;
    }
    return;
}
