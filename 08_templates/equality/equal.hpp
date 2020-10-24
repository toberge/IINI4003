#pragma once

#include <math.h>

#define BOOL_EQUALITY_TOLERANCE 0.00001

// Apparently templates _need_ to be defined in a header... why...

/// Generic equality checker (and absolutely redundant)
template <typename Type>
bool equal(Type a, Type b) {
    // haskell: equal :: (Eq a) => a -> a -> a
    return a == b; // assume that == is defined
}

/// Straightforward check of approximate equality
bool equal(double a, double b) {
    return abs(a - b) < BOOL_EQUALITY_TOLERANCE;
}
