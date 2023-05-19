#include "StartState.h"
#include "IdentifierState.h"
#include "Context.h"
#include <cctype>

using std::isdigit;
using std::isalpha;

void IdentifierState::handle(char simbol, LexerContext *context) {
    if (isalpha(simbol) || isdigit(simbol) || simbol == '_' || simbol == '-') {
        context->getTokenBuilder()->addValue(simbol);
    }
    else {
        context->getTokenBuilder()->setType(IDENTIFIER);
        context->storeToken();
        context->setState(new StartState);
        context->getState()->handle(simbol, context);
    }
    return;
}
