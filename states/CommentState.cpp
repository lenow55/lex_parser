#include "StartState.h"
#include "CommentState.h"
#include "Context.h"
#include <cctype>

void CommentOperatorState::handle(char simbol, LexerContext *context) {
    switch (simbol) {
//        case '/':
//            context->getTokenBuilder()->setType(OPERATOR);
//            context->setState(new CommentOperatorState);
//            break;
        case '*':
            context->setState(new CommentState);
            break;
        default:
            break;
    }
    return;
}

void CommentState::handle(char simbol, LexerContext *context) {
    switch (simbol) {
        case '*':
            context->setState(new CommentEndState);
            break;
        default:
            break;
    }
    return;
}

void CommentEndState::handle(char simbol, LexerContext *context) {
    switch (simbol) {
        case '/':
            context->setState(new StartState);
            break;
        default:
            context->setState(new CommentState);
            break;
    }
    return;
}
