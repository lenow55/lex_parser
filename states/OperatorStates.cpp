#include "OperatorStates.h"
#include "StartState.h"
#include "Context.h"

void AssignState::handle(char simbol, LexerContext *context) {
    switch (simbol) {
        case '=':
            context->getTokenBuilder()->addValue(simbol);
            context->getTokenBuilder()->setType(OPERATOR);
            context->storeToken();
            context->setState(new StartState);
            break;
        default:
            throw std::runtime_error(&"ERROR with this simbol: " [ simbol]);
            break;
    }
    return;
}
