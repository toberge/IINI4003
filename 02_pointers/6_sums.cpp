#include <iostream>

using namespace std;

int find_sum(const int *table, int length);

int main() {
    int table[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
                     12, 13, 14, 15, 16, 17, 18, 19, 20};
    
    int *pointer = table;
    // should be: sum [1..10] => 55
    cout << "Sum of first 10 numbers: " << find_sum(pointer, 10) << endl;
    pointer += 10;
    // should be: sum [11..15] => 65
    cout << "Sum of next 5 numbers: " << find_sum(pointer, 5) << endl;
    pointer += 5;
    // should be: sum [16..20] => 90
    cout << "Sum of last 5 numbers: " << find_sum(pointer, 5) << endl;
}

int find_sum(const int *table, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        /* cout << *table << endl; */
        sum += *table;
        table++;
    }
    return sum;
}
