#include "Scope.h"
#include "Token.h"
#include <cstddef>

Scope::Scope(Scope *parent_, const string& level_) :
    parent_scope(parent_), level(level_), hash_table(new HashMap){}

void Scope::storeToken(Token *token) {
    if (!parent_scope->lookUpCheck(token->getTokenValue())) {
        hash_table->set(token->getTokenValue(), token);
    }
}

bool Scope::lookUpCheck(const string &key) {
    if (hash_table->lookUpCheck(key)) {
        return true;
    }
    if (parent_scope->lookUpCheck(key)) {
        return true;
    }
    return false;
}
