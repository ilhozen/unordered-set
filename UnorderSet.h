#pragma once
#include"Node.h"
#include <string>
#include <iostream>
using namespace std;
class UnorderedSet {
public:
    // Constructors
    UnorderedSet();
    UnorderedSet(const UnorderedSet& other);
    ~UnorderedSet();

    // Element Access
    void printSet() const;
    bool contains(int value) const;

    // Modifiers
    void pop_front();
    void insert(int value);
    void remove(int value);
    void clear();

    // Capacity
    int size() const;
    bool isEmpty() const;

    //Other
    UnorderedSet intersection(const UnorderedSet& other) const;
    UnorderedSet setUnion(const UnorderedSet& other) const;
    UnorderedSet setDifference(const UnorderedSet& other) const;
    bool operator==(const UnorderedSet& lhs)const;

    friend ostream& operator<<(ostream& out, const UnorderedSet &list);
private:
    Node* head;
};
