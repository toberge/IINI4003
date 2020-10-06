#include "set.hpp"
#include <algorithm>
#include <iostream>

using namespace std;

// Creation

Set::Set() : elements() {}
Set::Set(const vector<int> &_elements) : elements(_elements) {}
Set::Set(const Set &other) : elements(other.elements) {}

// Assignment (not 100% necessary to declare)

Set &Set::operator=(const Set &other) {
    elements = other.elements;
    return *this;
}

// Insertion

// O(n) - would be O(1) with a map as chosen container
Set &Set::operator+=(const int element) {
    // if element is not already present
    if (find(elements.begin(), elements.end(), element) == elements.end()) {
        elements.emplace_back(element); // add it
    }
    return *this;
}

Set Set::operator+(const int element) const {
    Set new_set = *this;
    new_set += element;
    return new_set;
}

Set operator+(int element, const Set &set) {
    Set new_set = set;
    new_set += element;
    return new_set;
}

// Union

// O(n^2), would be O(n) with a map of some sort
// (technically O(nm) vs O(m))
// ... but this _entire class_ should use a map!
Set &Set::operator+=(const Set &other) {
    for (auto elem : other.elements) {
        *this += elem; // O(n)
    }
    return *this;
}

Set Set::operator+(const Set &other) const {
    Set new_set = *this;
    new_set += other;
    return new_set;
}

// Printing

ostream &operator<<(ostream &os, const Set &set) {
    os << "{ ";
    int n = set.elements.size()-1;
    for (int i = 0; i < n; i++) {
        os << set.elements[i] << ", ";
    }
    os << set.elements[n] << " }";
    return os;
}
