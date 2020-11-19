/**
 * Solutions for https://github.com/jmossberg/stlalgorithms
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

auto moreThanHundred = [](int x){ return x > 100; };

int main() {
    cout << "Exercise 1: Divisible by 5" << endl;
    vector<int> vec{1, 50, 3, 9, 18};
    auto it = find_if(vec.begin(), vec.end(), [](int x) { return x % 5 == 0; });
    cout << *it << endl;

    cout << endl << "Exercise 2: Substring search" << endl;
    string str = "Life is dull but algorithms are fun.";
    string sub = "are";
    auto it2 = search(str.begin(), str.end(), sub.begin(), sub.end());
    cout << "Found 'are' at " << (it2 - str.begin()) << endl;

    cout << endl << "Exercise 3: Filter (copy_if)" << endl;
    vector<int> vec3{1, 200, 5, 7, 900};
    vector<int> res3(2);
    copy_if(vec3.begin(), vec3.end(), res3.begin(), moreThanHundred);
    ostream_iterator<int> cout_it(cout, ", ");
    copy(res3.begin(), res3.end(), cout_it);
    cout << endl;

    cout << endl << "Exercise 4: Map (transform)" << endl;
    vector<int> vec4{2, 3, 4, 5};
    transform(vec4.begin(), vec4.end(), vec4.begin(), [](int x) { return 2*x; });
    copy(vec4.begin(), vec4.end(), cout_it);
    cout << endl;

    cout << endl << "Exercise 5: sort, unique, string::erase" << endl;
    string str5 = "aaccdffgfgfgiili";
    sort(str5.begin(), str5.end());
    auto erase_it = unique(str5.begin(), str5.end());
    /* while (erase_it != str5.end()) */
    /*     erase_it = str5.erase(erase_it); */
    str5.erase(erase_it, str5.end());
    cout << str5 << endl;

    cout << endl << "Exercise 6: stable_partition" << endl;
    vector<int> vec6{1 ,500 ,345 ,6 ,3 ,6};
    stable_partition(vec6.begin(), vec6.end(), moreThanHundred);
    copy(vec6.begin(), vec6.end(), cout_it);
    cout << endl;

    cout << endl << "Exercise 7: count_if" << endl;
    vector<int> vec7{1 ,500 ,345 ,6 ,3 ,6};
    int count = count_if(vec7.begin(), vec7.end(), moreThanHundred);
    cout << "Elements > 100: " << count << endl;
}
