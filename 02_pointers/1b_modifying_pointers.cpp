#include <iostream>

using namespace std;

int main() {
    // Initializations from task a)
    int i = 3;
    int j = 5;
    int *p = &i;
    int *q = &j;

    *p = 7;      // value at p is set -> i = 7
    *q += 4;     // value at q is increased -> j = 9 
    *q = *p + 1; // value at q is set w/p -> j = i + 1 = 8
    p = q;       // p now points to the same value as q -> j
    cout << *p << " " << *q << endl; // this should print "8 8"
}
