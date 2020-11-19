#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

void a() {
    vector<int> v1 = {1, 2};
    vector<int> v2 = {3, 4};
    copy(v2.begin(), v2.end(), v1.begin() + 2);
    for (auto e : v1)
      cout << e << endl;
}

void b() {
    vector<int> v1 = {1, 2};
    vector<int> v2 = {3, 4};
    v1.insert(v1.end(), v2.begin(), v2.begin() + 1);
    for (auto e : v1)
      cout << e << endl;
}

void c() {
    vector<int> v1 = {1, 2, 3, 4};
    cout << *find_if(v1.begin(), v1.end(), [](int e) {
      return e > 2;
    }) << endl;
}

void d() {
    vector<int> v1 = {1, 2};
    vector<int> v2 = {3, 4};
    cout << equal(v1.begin(), v1.end(), v2.begin(), [](int e1, int e2) {
      return e1 == e2 - 2;
    }) << endl;
}

void e() {
    vector<int> v1 = {1, 2};
    vector<int> v2 = {3, 4};
    cout << equal(v2.begin(), v2.end(), v1.begin(), [](int e1, int e2) {
      return e1 == e2 + 2;
    }) << endl;
}

int main() {
    cout << endl << "a)" << endl;
    a();

    cout << endl << "b)" << endl;
    b();

    cout << endl << "c)" << endl;
    c();

    cout << endl << "d)" << endl;
    d();

    cout << endl << "e)" << endl;
    e();
}
