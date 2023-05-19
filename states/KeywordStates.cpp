#include "StartState.h"
#include "KeywordStates.h"
#include "TokenBuilder.h"
#include "IdentifierState.h"
#include "Context.h"
#include <cctype>

using std::isdigit;
using std::isalpha;

void Else1State::handle(char simbol, LexerContext *context) {
    switch (simbol) {
        case 'l':
            context->getTokenBuilder()->addValue(simbol);
            context->setState(new Else2State);
            break;
        case '_':
        case '-':
            context->getTokenBuilder()->addValue(simbol);
            context->setState(new IdentifierState);
            break;
        default:
            if (isdigit(simbol) || isalpha(simbol)) {
                context->getTokenBuilder()->addValue(simbol);
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

void Else2State::handle(char simbol, LexerContext *context) {
    switch (simbol) {
        case 's':
            context->getTokenBuilder()->addValue(simbol);
            context->setState(new Else3State);
            break;
        case '_':
        case '-':
            context->getTokenBuilder()->addValue(simbol);
            context->setState(new IdentifierState);
            break;
        default:
            if (isdigit(simbol) || isalpha(simbol)) {
                context->getTokenBuilder()->addValue(simbol);
                context->setState(new IdentifierState);
                return;
            }
            context->getTokenBuilder()->setType(IDENTIFIER);
            context->storeToken();
            context->setState(new StartState);
            context->getState()->handle(simbol, context);
            break;
    }
    return;
}

void Else3State::handle(char simbol, LexerContext *context) {
    switch (simbol) {
        case 'e':
            context->getTokenBuilder()->addValue(simbol);
            context->setState(new Else4State);
            break;
        case '_':
        case '-':
            context->getTokenBuilder()->addValue(simbol);
            context->setState(new IdentifierState);
            break;
        default:
            if (isdigit(simbol) || isalpha(simbol)) {
                context->getTokenBuilder()->addValue(simbol);
                context->setState(new IdentifierState);
                return;
            }
            context->getTokenBuilder()->setType(IDENTIFIER);
            context->storeToken();
            context->setState(new StartState);
            context->getState()->handle(simbol, context);
            break;
    }
    return;
}

void Else4State::handle(char simbol, LexerContext *context) {
    if (isdigit(simbol) || isalpha(simbol) || simbol == '-' || simbol == '_') {
        context->getTokenBuilder()->addValue(simbol);
        context->setState(new IdentifierState);
        return;
    }
    context->getTokenBuilder()->setType(KEYWORD);
    context->storeToken();
    context->setState(new StartState);
    context->getState()->handle(simbol, context);
    return;
}

void If1State::handle(char simbol, LexerContext *context) {
    switch (simbol) {
        case 'f':
            context->getTokenBuilder()->addValue(simbol);
            context->setState(new If2State);
            break;
        case '_':
        case '-':
            context->getTokenBuilder()->addValue(simbol);
            context->setState(new IdentifierState);
            break;
        default:
            if (isdigit(simbol) || isalpha(simbol)) {
                context->getTokenBuilder()->addValue(simbol);
                context->setState(new IdentifierState);
                return;
            }
            context->getTokenBuilder()->setType(IDENTIFIER);
            context->storeToken();
            context->setState(new StartState);
            context->getState()->handle(simbol, context);
            break;
    }
    return;
}

void If2State::handle(char simbol, LexerContext *context) {
    if (isdigit(simbol) || isalpha(simbol) || simbol == '-' || simbol == '_') {
        context->getTokenBuilder()->addValue(simbol);
        context->setState(new IdentifierState);
        return;
    }
    context->getTokenBuilder()->setType(KEYWORD);
    context->storeToken();
    context->setState(new StartState);
    context->getState()->handle(simbol, context);
    return;
}

void Then1State::handle(char simbol, LexerContext *context) {
    switch (simbol) {
        case 'h':
            context->getTokenBuilder()->addValue(simbol);
            context->setState(new Then2State);
            break;
        case '_':
        case '-':
            context->getTokenBuilder()->addValue(simbol);
            context->setState(new IdentifierState);
            break;
        default:
            if (isdigit(simbol) || isalpha(simbol)) {
                context->getTokenBuilder()->addValue(simbol);
                context->setState(new IdentifierState);
                return;
            }
            context->getTokenBuilder()->setType(IDENTIFIER);
            context->storeToken();
            context->setState(new StartState);
            context->getState()->handle(simbol, context);
            break;
    }
    return;
}
void Then2State::handle(char simbol, LexerContext *context) {
    switch (simbol) {
        case 'e':
            context->getTokenBuilder()->addValue(simbol);
            context->setState(new Then3State);
            break;
        case '_':
        case '-':
            context->getTokenBuilder()->addValue(simbol);
            context->setState(new IdentifierState);
            break;
        default:
            if (isdigit(simbol) || isalpha(simbol)) {
                context->getTokenBuilder()->addValue(simbol);
                context->setState(new IdentifierState);
                return;
            }
            context->getTokenBuilder()->setType(IDENTIFIER);
            context->storeToken();
            context->setState(new StartState);
            context->getState()->handle(simbol, context);
            break;
    }
    return;
}
void Then3State::handle(char simbol, LexerContext *context) {
    switch (simbol) {
        case 'n':
            context->getTokenBuilder()->addValue(simbol);
            context->setState(new Then4State);
            break;
        case '_':
        case '-':
            context->getTokenBuilder()->addValue(simbol);
            context->setState(new IdentifierState);
            break;
        default:
            if (isdigit(simbol) || isalpha(simbol)) {
                context->getTokenBuilder()->addValue(simbol);
                context->setState(new IdentifierState);
                return;
            }
            context->getTokenBuilder()->setType(IDENTIFIER);
            context->storeToken();
            context->setState(new StartState);
            context->getState()->handle(simbol, context);
            break;
    }
    return;
}

void Then4State::handle(char simbol, LexerContext *context) {
    if (isdigit(simbol) || isalpha(simbol) || simbol == '-' || simbol == '_') {
        context->getTokenBuilder()->addValue(simbol);
        context->setState(new IdentifierState);
        return;
    }
    context->getTokenBuilder()->setType(KEYWORD);
    context->storeToken();
    context->setState(new StartState);
    context->getState()->handle(simbol, context);
    return;
}
