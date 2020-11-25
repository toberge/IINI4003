#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    {
        cout << "Oppgave 5a)" << endl;
        vector<int> vec = {2, 5, 2, 5, 1, 5, 1};
        reverse(vec.begin(), vec.end());
        for (auto &e : vec)
            cout << e << endl;
    }
    {
        cout << endl << "Oppgave 5b)" << endl;
        vector<int> vec = {2, 5, 2, 5, 1, 5, 1};
        rotate(vec.begin(), vec.begin()+1, vec.end());
        for (auto &e : vec)
            cout << e << endl;
    }
    {
        cout << endl << "Oppgave 5c)" << endl;
        vector<int> vec = {2, 5, 2, 5, 1, 5, 1};
        transform(vec.begin(), vec.end(), vec.begin(), [](int x){ return 2*x; });
        for (auto &e : vec)
            cout << e << endl;
    }
}
