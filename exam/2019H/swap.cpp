#include <iostream>

/**
 * Oppgave 1
 * Swap back-and-forth between different types (ptrs and refs)
 */

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap(int *a, int &b) {
    int temp = *a;
    *a = b;
    b = temp;
}

// not needed
void swap(int &a, int *b) {
    int temp = a;
    a = *b;
    *b = temp;
}

int main() {
    int a = 1, b = 2;
    swap(a, b);
    std::cout << a << ' ' << b << std::endl;
    swap(&a, &b);
    std::cout << a << ' ' << b << std::endl;
    auto c = &a;
    auto d = &b;
    swap(c, *d);
    std::cout << *c << ' ' << *d << std::endl;
}
