#include <iostream>

using namespace std;

int main() {
    int i = 3;
    int j = 5;
    int *p = &i;
    int *q = &j;

    cout << "i=" << i << " &i=" << &i << endl;
    cout << "p=" << p << " &p=" << &p << endl;

    cout << "j=" << j << " &j=" << &j << endl;
    cout << "q=" << q << " &q=" << &q << endl;
}

/*
 * Sample output:
 *
 * i=3 &i=0x7ffeed8a94e0
 * p=0x7ffeed8a94e0 &p=0x7ffeed8a94e8
 * j=5 &j=0x7ffeed8a94e4
 * q=0x7ffeed8a94e4 &q=0x7ffeed8a94f0
 *
 * It is evident that p == &i
 * and that p is stored at a different address,
 * as expected.
 * The same goes for j and q.
 *
 * Ja, utskriften stemte med tegningen min.
 */
