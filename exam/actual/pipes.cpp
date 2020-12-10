#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

// Note: This could be written generically with templates.
//       The specified source code does not allow for that.

using namespace std;

/// Map class
class Map {
private:
    /// Mapping function like you'd pass to filer() in a functional language
    function<int(int)> mapfun;
public:
    Map(const function<int(int)> mapfun) : mapfun(mapfun) {}

    /// Pipe a vector to a mapping
    friend vector<int> operator|(const vector<int> &vec, const Map &map) {
        vector<int> transformed;
        transformed.reserve(vec.size()); // reserve enough space
        for (int elem : vec)
            transformed.emplace_back(map.mapfun(elem)); // append transformed element
        return transformed;
    }
};

/// Filter class
class Filter {
private:
    /// Predicate function like you'd pass to filer() in a functional language
    function<bool(int)> predicate;
public:
    Filter(const function<bool(int)> predicate) : predicate(predicate) {}

    /// Pipe a vector to a filter
    friend vector<int> operator|(const vector<int> &vec, const Filter &filter) {
        vector<int> filtered;
        filtered.reserve(vec.size()); // reserve (more than) enough space
        int count = 0;
        for (int elem : vec) {
            if (filter.predicate(elem)) { // if the filter allows this element
                count++;
                filtered.emplace_back(elem); // append it
            }
        }
        filtered.resize(count); // resize to match output size
        return filtered;
    }
};

/// << operator overload for printing a vector
template<typename T>
ostream &operator<<(ostream &os, vector<T> &vec) {
    os << "{";
    for (int i = 0; i < vec.size() - 1; i++)
        os << vec[i] << ", ";
    // ugly special case for last elem
    if (vec.size() > 0) os << vec[vec.size()-1];
    return os << "}";
}

int main() {
    vector<int> vec = {1, 2, 3};

    vector<int> vecMultipliedBy2 = vec | Map([](int e) { return e * 2; });
    cout << vecMultipliedBy2 << endl;
    // {2, 4, 6}

    vector<int> vecFiltered = vec | Filter([](int e) { return e % 2 == 1; });
    cout << vecFiltered << endl;
    // {1, 3}
}
