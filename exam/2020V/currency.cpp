#include <iostream>

using namespace std;

// LF does static class with rate
// Having a non-abstract class would let this be abstract...

class Coinage {
public: 
    virtual double to_euro(double amount) const = 0;
};

class NorwegianKrone : public Coinage {
public: 
    double to_euro(double amount) const override {
        return amount * 0.1;
    }
};

class Euro : public Coinage {
public: 
    double to_euro(double amount) const override {
        return amount;
    }
};

template<typename T>
class Currency {
private:
    long amount;
    T coinage;
public:
    Currency(long _amount) : amount(_amount) {}

    /* I did NOT want this solution:
    Currency<Euro> operator+(const Currency<Euro> other) {
        return Currency<Euro>(to_euro() + other.to_euro());
    }
    Currency<Euro> operator+(const Currency<NorwegianKrone> other) {
        return Currency<Euro>(to_euro() + other.to_euro());
    }
    */
    template<typename K>
    Currency<K> operator+(const Currency<K> other) {
        return Currency<K>(to_euro() + other.to_euro());
    }

    double to_euro() const {
        return coinage.to_euro(amount);
    }

    double get_amount() const { // useless here, 'xcept for testing
        return amount;
    }

    friend ostream &operator<<(ostream &os, const Currency<T> &currency) {
        os << "€" << currency.coinage.to_euro(currency.amount);
        return os;
    }
};

int main() {
    cout << Currency<NorwegianKrone>(1) << endl;
    cout << Currency<Euro>(1) << endl;
    cout << (Currency<NorwegianKrone>(10) +
             Currency<Euro>(10) +
             Currency<NorwegianKrone>(10)) << endl;
}
