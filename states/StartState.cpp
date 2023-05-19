#include "StartState.h"
#include "CommentState.h"
#include "OperatorStates.h"
#include "KeywordStates.h"
#include "StringState.h"
#include "NumberState.h"
#include "IdentifierState.h"
#include "TokenBuilder.h"
#include "Context.h"
#include <cctype>

using std::isdigit;
using std::isalpha;

void StartState::handle(char simbol, LexerContext *context) {
    context->clearTokenBuilder();
    context->getTokenBuilder()->addValue(simbol);
    switch (simbol) {
        case '<':
        case '>':
            context->getTokenBuilder()->setType(COMPARE);
            context->storeToken();
            break;
        case ':':
            context->setState(new AssignState);
            break;
        case '/':
            context->setState(new CommentOperatorState);
            break;
        case '*':
        case '+':
        case '-':
            context->getTokenBuilder()->setType(OPERATOR);
            context->storeToken();
            break;
        case 'e':
            context->setState(new Else1State);
            break;
        case 'i':
            context->setState(new If1State);
            break;
        case 't':
            context->setState(new Then1State);
            break;
        case '\"':
            context->setState(new StringState);
        case ';':
        case '(':
        case ')':
            context->getTokenBuilder()->setType(DELIMITER);
            context->storeToken();
            break;
        case ' ':
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
            throw std::runtime_error(&"ERROR with this simbol: " [ simbol]);
            break;
    }
    return;
}
