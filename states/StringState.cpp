#include "StartState.h"
#include "CompareState.h"
#include "OperatorStates.h"
#include "KeywordStates.h"
#include "StringState.h"
#include "NumberState.h"
#include "IdentifierState.h"
#include "CommentState.h"
#include "Token.h"
#include "TokenBuilder.h"
#include "Context.h"
#include <cctype>

using std::isdigit;
using std::isalpha;

void StartState::handle(char simbol, LexerContext *context) {
    context->createTokenBuilder();
    context->getTokenBuilder()->addValue(simbol);
    switch (simbol) {
        case '<':
        case '>':
            context->getTokenBuilder()->setType(COMPARE);
            context->setState(new CompareState);
            break;
        case ':':
            context->getTokenBuilder()->setType(OPERATOR);
            context->setState(new AssignOperatorStateFirst);
            break;
        case '/':
            context->getTokenBuilder()->setType(OPERATOR);
            context->setState(new CommentOperatorState);
            break;
        case '*':
        case '+':
        case '-':
            context->getTokenBuilder()->setType(OPERATOR);
            context->setState(new OperatorState);
            break;
        case 'e':
            context->getTokenBuilder()->setType(KEYWORD);
            context->setState(new Else1State);
            break;
        case 'i':
            context->getTokenBuilder()->setType(KEYWORD);
            context->setState(new If1State);
            break;
        case 't':
            context->getTokenBuilder()->setType(KEYWORD);
            context->setState(new Then1State);
            break;
        case '\"':
            context->getTokenBuilder()->setType(STRING);
            context->setState(new StringState);
        case ';':
        case '(':
        case ')':
            context->getTokenBuilder()->setType(DELIMITER);
            context->setState(new DelimiterState);
            break;
        case ' ':
            break;
        case '_':
            context->getTokenBuilder()->setType(DELIMITER);
            context->setState(new DelimiterState);
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