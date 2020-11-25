#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    {
        cout << "Oppgave 5a)" << endl;
        vector<int> vec = {2, 5, 2, 5, 1, 5, 1};
        // Standard sort
        sort(vec.begin(), vec.end());
        for (auto &e : vec)
            cout << e << endl;
    }
    {
        cout << endl << "Oppgave 5b)" << endl;
        vector<int> vec = {2, 5, 2, 5, 1, 5, 1};
        // Standard sort
        sort(vec.begin(), vec.end());
        // Then uniq
        auto it = unique(vec.begin(), vec.end());
        vec.erase(it, vec.end());
        for (auto &e : vec)
            cout << e << endl;
    }
    {
        cout << endl << "Oppgave 5c)" << endl;
        vector<int> vec = {2, 5, 2, 5, 1, 5, 1};
        // Reverse sort
        sort(vec.begin(), vec.end(), [](int a, int b){ return a>b; });
        // Then uniq
        auto it = unique(vec.begin(), vec.end());
        vec.erase(it, vec.end());
        for (auto &e : vec)
            cout << e << endl;
    }
}
