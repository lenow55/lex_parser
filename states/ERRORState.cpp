#include "ERRORState.h"
#include "StartState.h"
#include "Context.h"

void ErrorState::handle(char simbol, LexerContext *context) {
    switch (simbol) {
        case ' ':
        case ';':
        case ')':
        case '(':
        case '\n':
        case '\t':
        case '\0':
        case -1:
            context->getTokenBuilder()->setType(ERROR);
            context->storeToken();
            context->setState(new StartState);
            break;
        default:
            context->getTokenBuilder()->addValue(simbol);
            break;
    }
    return;
}
