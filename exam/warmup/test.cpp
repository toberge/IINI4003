#include <string>
#include <iostream>

using namespace std;

class Astronaut {
public:
    string name;
    Astronaut(const string &name) : name(name) {}
};

int main() {
    string name = "Buzz Aldrin";
    auto a = Astronaut(name);
    cout << a.name << endl;
    name[1] = 'a';
    cout << "name: " << name << ", a.name: " << a.name << endl;
}
