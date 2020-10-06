#include "set.hpp"
#include <iostream>

auto main() -> int {
    Set set(vector<int>{1, 2, 3});
    Set otherset(vector<int>{9,3,6});

    cout << "Starting with " << set << " and " << otherset << endl;

    cout << endl;
    cout << "Demonstrating insertion" << endl;
    cout << "Constant, from both sides" << endl;
    cout << set << " then " << 4 + set + (-4) + 10 << endl;
    cout << "Mutating" << endl;
    set += 5;
    cout << set << endl;

    cout << endl;
    cout << "Demonstrating union" << endl;
    cout << "Constant" << endl;
    cout << set + otherset << endl;
    cout << "While the originals are intact: "
         << set << " and " << otherset << endl;
    set += otherset;
    cout << "Mutating" << endl;
    cout << set << endl;

    cout << endl;
    cout << "Demonstrating assignment" << endl;
    Set thirdset = otherset;
    cout << "Another set with " << thirdset << endl;
    thirdset += 12;
    cout << "Mutating the copy " << thirdset
         << " leaves the original " << otherset << " intact." << endl;

    return 0;
}
