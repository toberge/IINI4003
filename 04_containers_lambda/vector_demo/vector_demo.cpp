#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

auto main() -> int {
    vector<double> nums = { 1.618033988, 2.0, 2.718281828, 3.0, 3.1415 };

    // Get head and tail
    cout << "front & back" << endl;
    cout << nums.front() << endl
         << nums.back() << endl;

    // etter det første elementet, sier du?
    // da skriver jeg ut litt mer enn bare front()
    nums.emplace((++nums.begin()), 1.9);
    cout << "Emplaced " << nums[1] << " after " << nums.front() << endl;

    // Find is successful if it does not return the end() iterator
    // Let's demonstrate that by searching for the _last_ element,
    // which should lie right before nums.end()
    auto find_result = find(nums.begin(), nums.end(), 3.1415);
    if (find_result != nums.end()) {
        cout << "find() worked, found "
             << *find_result << endl;
    }
}
