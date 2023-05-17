#include "CommentState.h"
#include <cctype>

using std::isdigit;

void CommentState::handle(char simbol, LexerContext *context) {
    if (isdigit(simbol)) {
    }
}

