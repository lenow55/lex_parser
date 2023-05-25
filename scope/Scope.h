#pragma once

#include <cstddef>
#include <string>
#include <ostream>
#include "HashMap.h"
#include "Token.h"

using std::string;
using std::size_t;

class Scope {
    private:
        Scope *parent_scope;
        size_t level;
        size_t count_child;
        size_t index;
        HashMap *hash_table;
    public:
        Scope(Scope *, size_t, size_t);
        ~Scope();
        void storeToken(Token *);
        bool lookUpCheck(const string&);
        Scope *getParentScope();
        size_t getLevel();
        size_t getIndex();
        size_t getCountChild();
        void increaseChild();
        friend std::ostream &operator<<(std::ostream &, const Scope &);
};
