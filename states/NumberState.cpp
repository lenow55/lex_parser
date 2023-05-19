#include "StartState.h"
#include "Token.h"
#include "TokenBuilder.h"
#include "Context.h"
#include <cctype>
#include <stdexcept>

using std::isdigit;
using std::isalpha;

void StartState::handle(char simbol, LexerContext *context) {
    if (isdigit(simbol)) {
        context->getTokenBuilder()->addValue(simbol);
    }
    if (isalpha(simbol) || simbol == '_') {
        throw std::runtime_error(&"ERROR with this simbol: " [ simbol]);
    }
    context->getTokenBuilder()->setType(NUMBER);
    context->storeToken();
    context->setState(new StartState);
    context->getState()->handle(simbol, context);
    return;
}
