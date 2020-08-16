#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char *line = nullptr;
    strcpy(line, "Dette er en tekst");
    cout << line << endl;
    cout << &line << endl;

    int *x = nullptr;
    cout << &x << endl;
}
