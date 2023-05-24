#pragma once

#include "Token.h"
//#include <cstddef>
//#include <string>
//#include <ostream>
//
//using std::string;
//using std::size_t;

class Bucket {
    string key;
    Token* value;
    bool emptySinceStart;
    bool emptySinceRemoval;
    public:
    Bucket();
    void set(const string &, Token*);
    void remove();
    bool isEmptySinceStart() const;
    bool isEmptySinceRemoval() const;
    bool isEmpty() const;
    const string& getKey() const;
    Token* getValue() const;
};

// HashMap
// Linear probing
class HashMap {
    int capacity;
    Bucket *buckets;  // 1D array of buckets
    int hashFunction(const string &);
    // probing algorithm
    int probe(int hash, int probed);
    public:
    HashMap(int capacity = 100);
    ~HashMap();
    bool set(const string &, Token*);
    bool remove(const string &);
    const Token *lookUp(const string &);
    bool lookUpCheck(const string &);
    void rehash();
};
