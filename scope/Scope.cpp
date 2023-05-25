#include "Scope.h"
#include "Token.h"
#include <cstddef>

Scope::Scope(Scope *parent_, size_t level_, size_t index_) :
    parent_scope(parent_),
    level(level_),
    index(index_),
    count_child(0),
    hash_table(new HashMap){}

void Scope::storeToken(Token *token) {
    if (!this->lookUpCheck(token->getTokenValue())) {
        hash_table->set(token->getTokenValue(), token);
    }
}

bool Scope::lookUpCheck(const string &key) {
    if (hash_table->lookUpCheck(key)) {
        return true;
    }
    if (parent_scope == nullptr) {
        return false;
    }
    if (parent_scope->lookUpCheck(key)) {
        return true;
    }
    return false;
}

Scope *Scope::getParentScope() {
    return parent_scope;
}

Scope::~Scope() {
    delete hash_table;
    parent_scope = nullptr;
}

size_t Scope::getLevel() {
    return this->level;
}
size_t Scope::getIndex() {
    return this->index;
}

size_t Scope::getCountChild() {
    return this->count_child;
}

void Scope::increaseChild() {
    ++this->count_child;
}

std::ostream &operator<<(std::ostream &os, const Scope &scope) {
    os << "Level: " << scope.level << "-" << scope.index << '\n';
    os << *(scope.hash_table);
    return os;
}
