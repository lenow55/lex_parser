#include "StartState.h"
#include "CompareState.h"
#include "CommentState.h"
#include "OperatorStates.h"
#include "KeywordStates.h"
#include "StringState.h"
#include "NumberState.h"
#include "IdentifierState.h"
#include "Token.h"
#include "TokenBuilder.h"
#include "Context.h"
#include <cctype>

void CommentOperatorState::handle(char simbol, LexerContext *context) {
    switch (simbol) {
        case '/':
//            context->getTokenBuilder()->setType(OPERATOR);
//            context->setState(new CommentOperatorState);
            break;
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
            context->setState(new CommentState);
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
