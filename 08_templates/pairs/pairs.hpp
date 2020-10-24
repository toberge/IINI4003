#pragma once

// Implementation in a header file? Heresy!

// a Pair has two values of different or equal type
template <typename TypeA, typename TypeB>
class Pair {
public:
    TypeA first;
    TypeB second;
    Pair(TypeA _first, TypeB _second) : first(_first), second(_second) {}
    // Elementwise sum
    Pair operator+(Pair &other) {
        Pair new_pair = *this;
        new_pair.first += other.first;
        new_pair.second += other.second;
        return new_pair;
    }
    // Elementwise comparison
    double operator>(Pair &other) {
        return first > other.first && second > other.second;
    }
};
