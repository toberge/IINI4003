#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class Animal {
private:
    string name;
public:
    Animal(const string &_name) : name(_name) {}
    virtual string type() const = 0;
    friend ostream &operator<<(ostream &os, const Animal &animal) {
        os << animal.type() << " named " << animal.name;
        return os;
    }
};

class Cat : public Animal {
public:
    Cat(const string &_name) : Animal(_name) {}
    string type() const override {
        return "Cat";
    }
};

class Dog : public Animal {
public:
    Dog(const string &_name) : Animal(_name) {}
    string type() const override {
        return "Dog";
    }
};

int main() {
    vector<unique_ptr<Animal>> animals;
    animals.emplace_back(new Cat("Oreo"));
    animals.emplace_back(new Dog("Buddy"));
    animals.emplace_back(new Dog("Charlie"));
    // animals.emplace_back(new Animal()); // Should cause compilation error
    // animals.emplace_back(new Animal("Max")); // Should cause compilation error
    for (auto &animal : animals)
        cout << *animal << endl;
}
