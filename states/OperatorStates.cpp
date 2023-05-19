#include "OperatorStates.h"
#include "StartState.h"
#include "Context.h"
#include "ERRORState.h"

void AssignState::handle(char simbol, LexerContext *context) {
    context->getTokenBuilder()->addValue(simbol);
    switch (simbol) {
        case '=':
            context->getTokenBuilder()->setType(OPERATOR);
            context->storeToken();
            context->setState(new StartState);
            break;
        default:
            context->setState(new ErrorState);
            break;
    }
    return;
}
