#include <iostream>

using namespace std;

// Base class to avoid code duplication
class Number {
private:
    int value;
public:
    Number(int value) : value(value) {}

    Number operator-() {
        return Number(-value);
    }

    Number operator+(Number &other) {
        return Number(value + other.value);
    }

    Number operator*(Number &other) {
        return Number(value * other.value);
    }

    // ...had to abandon reference...
    // - NO, you don't need to do that:
    //   Use const Something &something to make it accept lvalues
    friend ostream &operator<<(ostream &os, const Number &num) {
        return os << num.value;
    }
};

// Instances with specific values
class One : public Number {
public:
    One() : Number(1) {}
};

class Two : public Number {
public:
    Two() : Number(2) {}
};

int main() {
    One one;
    Two two;
    cout << one << endl;
    cout << two * one << endl;
    cout << two * one + one << endl;
    cout << -(two * one + one) << endl;
}
