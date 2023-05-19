#include "StartState.h"
#include "StringState.h"
#include "Context.h"

void StringState::handle(char simbol, LexerContext *context) {
    context->getTokenBuilder()->addValue(simbol);
    if (simbol == '\"') {
        context->getTokenBuilder()->setType(STRING);
        context->storeToken();
        context->setState(new StartState);
    }
    return;
}
