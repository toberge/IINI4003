#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Engine {
public:
    virtual const string get_type() const = 0;
};

class Gasoline : public Engine {
public:
    const string get_type() const override {
        return "gasoline";
    };
};

class Electric : public Engine {
public:
    const string get_type() const override {
        return "electric";
    };
};

class Car {
public:
    virtual const string get_type() const = 0;
    virtual const string get_engine() const = 0;
};

// this does NOT seem ideal
template<typename T>
class Saab : public Car {
private:
    const T engine;
public:
    Saab() : engine() {}
    const string get_type() const override {
        return "Saab";
    }
    const string get_engine()  const override {
        return engine.get_type();
    };
};

template<typename T>
class Volvo : public Car {
private:
    const T engine;
public:
    Volvo() : engine() {}
    const string get_type() const override {
        return "Volvo";
    }
    const string get_engine()  const override {
        return engine.get_type();
    };
};

ostream &operator<<(ostream &os, const Car &car) {
    os << car.get_type() << " with " << car.get_engine() << " engine";
    return os;
}

int main() {
    vector<unique_ptr<Car>> cars;
    cars.emplace_back(new Saab<Electric>());
    cars.emplace_back(new Saab<Gasoline>());
    cars.emplace_back(new Volvo<Electric>());
    for (auto &car : cars)
        cout << *car << endl;
}
