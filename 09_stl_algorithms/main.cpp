#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Dette var en altfor enkel øving.
// Nesten ingenting å gjøre.
// Men: Dette har vært en liten smak på noe jeg *liker* ved c++,
// et språk jeg ellers har lite til overs for.
// Kanskje jeg endrer mening etterhvert, hvem vet.

ostream &operator<<(ostream &out, const vector<int> &vec) {
    for (auto &elem : vec)
        out << elem << " ";
    return out;
}

int main() {
    vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
    cout << "v1: " << v1 << endl;
    vector<int> v2 = {2, 3, 12, 14, 24};
    cout << "v2: " << v2 << endl;

    cout << endl << "Oppgave a) - større enn 15" << endl;
    auto it = find_if(v1.begin(), v2.end(), []( int a) {
            return a > 15;
    });
    cout << *it << " > 15" << endl;

    // Forskjell mindre eller lik 2...
    auto almost_equal = [](int a, int b) {
            return abs(a-b) <= 2;
    };

    cout << endl << "Oppgave b.1) - er v[0:5] og v2 omtrent like?" << endl;
    if (equal(v1.begin(), v1.begin() + 5, v2.begin(), almost_equal)) {
        cout << "Ja, det er de" << endl;
    } else {
        cout << "Nei, det er de jaggu meg ikke" << endl;
    }

    cout << endl << "Oppgave b.2) - er v[0:4] og v2 omtrent like?" << endl;
    if (equal(v1.begin(), v1.begin() + 4, v2.begin(), almost_equal)) {
        cout << "Ja, det er de" << endl;
    } else {
        cout << "Nei, det er de jaggu meg ikke" << endl;
    }

    cout << endl << "Oppgave c) - erstatt alle oddetall med 100" << endl;
    // v1.begin() as output → will replace
    replace_copy_if(v1.begin(), v1.end(), v1.begin(), [](int a) {
            return a % 2 == 1;
    }, 100);
    cout << v1 << endl;
}
