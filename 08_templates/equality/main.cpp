#include <iostream>
#include <iomanip>
#include "equal.hpp"

using namespace std;

int main() {
    double a = 3.1415;
    double b = 2.718281828;
    
    cout << "Inequal values are inequal:" << endl;
    cout << a << " == " << b << " -> " << equal(a, b) << endl;

    a = 1.0000002;
    b = 1.0000003;
    cout << "Almost equal values are equal:" << endl;
    cout << setprecision(8)
         << a << " == " << b << " -> " << equal(a, b) << endl;
    cout << "With standard == operator: " << (a == b) << endl;
    cout << "This clearly shows that the double-specific version is used." << endl;

    cout << endl << "Testing the templated version with ints and strings:" << endl;
    int e = 4, f = 4;
    cout << e << " == " << f << " -> " << equal(e, f) << endl;
    /* string c = "Hello world"; */
    /* string d = "Hello world"; */
    /* cout << c << " == " << d << " -> " << equal(c, d) << endl; */
}
