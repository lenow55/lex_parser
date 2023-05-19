#include "StartState.h"
#include "KeywordStates.h"
#include "TokenBuilder.h"
#include "IdentifierState.h"
#include "Context.h"

using std::isdigit;
using std::isalpha;

void Else1State::handle(char simbol, LexerContext *context) {
    switch (simbol) {
        case 'l':
            context->getTokenBuilder()->addValue(simbol);
            context->setState(new Else2State);
            break;
        default:
            if (isdigit(simbol)) {
                context->getTokenBuilder()->addValue(simbol);
                throw std::runtime_error(&"ERROR with this simbol: " [ simbol]);
                return;
            }
            if (isalpha(simbol)) {
                context->getTokenBuilder()->addValue(simbol);
                context->getTokenBuilder()->setType(IDENTIFIER);
                context->setState(new IdentifierState);
                return;
            }
            context->getTokenBuilder()->setType(IDENTIFIER);
            context->storeToken();
            context->setState(new StartState);
            // это мне не нравится, хотелось бы вызывать
            // эту функцию из контекста, а не из состояния
            context->getState()->handle(simbol, context);
            break;
    }
    return;
}
