#include <iostream>

/**
 * This became REALLY bad
 * ...it technically works, but it's not ideal by far
 */

using namespace std;

class Degrees {
public:
    Degrees *operator+() const;
    Degrees *operator-() const;
    virtual const string description() const {
        return "normal";
    };
};

class Hot : public Degrees {
public:
    const string description() const override {
        return "hot";
    }
};
class Cold : public Degrees {
public:
    const string description() const override {
        return "cold";
    }
};

Degrees *Degrees::operator+() const {
    Hot *hot = new Hot;
    return dynamic_cast<Degrees*>(hot);
}

Degrees *Degrees::operator-() const {
    Cold *hot = new Cold;
    return dynamic_cast<Degrees*>(hot);
}

ostream &operator<<(ostream &os, const Degrees *deg) {
    os << deg->description();
    return os;
}

int main() {
    Degrees degrees;
    // memory leaks here!
    cout << +degrees << endl;
    cout << -degrees << endl;
}
