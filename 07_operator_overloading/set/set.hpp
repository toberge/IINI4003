#include <iostream>
#include <vector>

#pragma once

/**
 * - create empty set
 * - union of two sets (+)
 * - adding a number to a set (+)
 * - setting a set equal to another set (=)
 * - printing a set (ostream's <<)
 */

using namespace std;

class Set {
private:
    vector<int> elements;
    friend ostream;
public:
    Set();
    Set(const vector<int>& _elements);
    Set(const Set&); // necessitated by deifining assignment

    // Union
    Set operator+(const Set &other) const;
    Set &operator+=(const Set &other);

    // Insertion
    Set operator+(const int element) const;
    Set &operator+=(const int element);

    // Assignment (not necessary to explicitly declare)
    Set &operator=(const Set &other);

    // Printing
    friend ostream &operator<<(ostream &os, const Set &foo);
};

Set operator+(int element, const Set &other);
