#include <iostream>
#include <vector>

using namespace std;

int f(int a, int &b, int *c) {
  a++;
  b -= a;
  *c += a;
  return a;
}

int main() {
    {
        cout << "Oppgave 1a)" << endl;
        vector<int> vec = {1, 4, 3, 5, 2};
        auto p = &vec[0];
        p++;
        cout << *p << *(p + 2) << endl;
    }
    {
        cout << endl << "Oppgave 1b)" << endl;
        int a = 19;
        int b = 21;
        int c = -11;
        a = f(a, b, &c);
        cout << a << b << c << endl;
    }
    {
        cout << endl << "Oppgave 1c)" << endl;
        string str = "test";
        cout << ((char *)&str == &str[0]) << endl;
        cout << (str[0] == str[3]) << endl;
        cout << (&str[3] == &str[0]) << endl;
        cout << (int)str[4] << endl;

        cout << endl << "Demo av feilen min i 1c)" << endl;
        cout << ((char *)&str) << "\tmed adresse ";
        cout << ((long)(char *)&str) << endl;
        cout << (&(str[0])) << "\tmed adresse ";
        cout << ((long)&(str[0])) << endl;
        cout << "Avstand: " << ((long)&(str[0]) - (long)(char *)&str) << " bytes." << endl;
    }
}
