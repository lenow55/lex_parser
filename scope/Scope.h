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
        string level;
        HashMap *hash_table;
    public:
        Scope(Scope *, const string&);
        ~Scope();
        void storeToken(Token *);
        bool lookUpCheck(const string&);
        friend std::ostream &operator<<(std::ostream &os, const Scope &scope_);
};
