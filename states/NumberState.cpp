#include "NumberState.h"
#include "StartState.h"
#include "Token.h"
#include "TokenBuilder.h"
#include "ERRORState.h"
#include "Context.h"
#include <cctype>

using std::isdigit;
using std::isalpha;

void NumberState::handle(char simbol, LexerContext *context) {
    if (isdigit(simbol)) {
        context->getTokenBuilder()->addValue(simbol);
        return;
    }
    if (isalpha(simbol) || simbol == '_') {
        context->getTokenBuilder()->addValue(simbol);
        context->setState(new ErrorState);
        return;
    }
    context->getTokenBuilder()->setType(NUMBER);
    context->storeToken();
    context->setState(new StartState);
    context->getState()->handle(simbol, context);
    return;
}
