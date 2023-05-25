#include "HashMap.h"
#include "Token.h"
#include <cstddef>
#include <stdexcept>

Bucket::Bucket() :
    key(""),
    value(nullptr),
    emptySinceStart(true),
    emptySinceRemoval(false) {}

    Bucket::~Bucket() {
        delete value;
    }

void Bucket::set(const string &key_, Token* value_) {
    this->key = key_;
    this->value = value_;
    emptySinceStart = false;
    emptySinceRemoval = false;
}

void Bucket::remove() {
    key = "";
    delete value;
    emptySinceRemoval = true;
}

bool Bucket::isEmptySinceStart() const {
    return emptySinceStart;
}

bool Bucket::isEmptySinceRemoval() const {
    return emptySinceRemoval;
}

bool Bucket::isEmpty() const {
    return emptySinceStart || emptySinceRemoval;
}

const string& Bucket::getKey() const {
    return key;
}

Token* Bucket::getValue() const {
    return value;
}

//HashMap functions
HashMap::HashMap(int capacity) {
    this->capacity = capacity;
    buckets = new Bucket[capacity];
}

HashMap::~HashMap() {
    delete[] buckets;
}

int HashMap::hashFunction(const string &key) {
    int hash = 0;
    size_t length = key.length();
    if (length > 15)
        length = 15;
    for (size_t i = 0; i < length; i++) {
        hash += key[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);

    // Ensure positive values
    if (hash < 0) {
        hash *= -1;
    }

    return hash % capacity;
}

int HashMap::probe(int hash, int probed) {
    return (hash + probed) % capacity;
}

bool HashMap::set(const string &key, Token *value) {
    int hash = hashFunction(key);
    for (int i = 0; i < capacity; i++) {
        int idx = probe(hash, i);
        if (buckets[idx].isEmpty()) {
            buckets[idx].set(key, value);
            return true;
        } else if (buckets[idx].getKey() == key) {
            buckets[idx].set(key, value); // override existing key
            return true;
        }
    }

    // hash map is full, rehash and try again
    rehash();
    return set(key, value);
}

bool HashMap::remove(const string &key) {
    int hash = hashFunction(key);
    for (int i = 0; i < capacity; i++) {
        int idx = probe(hash, i);
        if (buckets[idx].isEmptySinceStart()) {
            return false; // key not found
        }
        if (buckets[idx].getKey() == key) {
            buckets[idx].remove();
            return true;
        }
    }
    return false; // key not found
}

const Token *HashMap::lookUp(const string &key) {
    int hash = hashFunction(key);
    for (int i = 0; i < capacity; i++) {
        int idx = probe(hash, i);
        if (buckets[idx].isEmptySinceStart()) {
            throw std::runtime_error("Key not found");
        }
        if (buckets[idx].getKey() == key) {
            return buckets[idx].getValue();
        }
    }
    throw std::runtime_error("Key not found");
}

bool HashMap::lookUpCheck(const string &key) {
    int hash = hashFunction(key);
    for (int i = 0; i < capacity; i++) {
        int idx = probe(hash, i);
        if (buckets[idx].isEmptySinceStart()) {
            return false;
        }
        if (buckets[idx].getKey() == key) {
            return true;
        }
    }
    return false;
}

void HashMap::rehash() {
    int oldCapacity = capacity;
    Bucket *oldBuckets = buckets;

    capacity *= 2;
    buckets = new Bucket[capacity];

    for (int i = 0; i < oldCapacity; i++) {
        if (!oldBuckets[i].isEmpty()) {
            const string &key = oldBuckets[i].getKey();
            Token *value = oldBuckets[i].getValue();

            int hash = hashFunction(key);
            for (int j = 0; j < capacity; j++) {
                int idx = probe(hash, j);
                if (buckets[idx].isEmpty()) {
                    buckets[idx].set(key, value);
                    break;
                }
            }
        }
    }

    delete[] oldBuckets;
}


std::ostream &operator<<(std::ostream &os, const HashMap &hashMap) {
    for (int i = 0; i < hashMap.capacity; i++) {
        if (!hashMap.buckets[i].isEmpty()) {
            os << "Hash: " << i
                << ", Value: " << *(hashMap.buckets[i].getValue()) << "\n";
        }
    }
    return os;
}
