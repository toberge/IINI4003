#include <iostream>

using namespace std;

int main() {
    char text[5];
    char *pointer = text;
    char search_for = 'e';
    cin >> text; // according to the definition, this will read 5 chars

    // This while loop will enter unallocated memory
    // if the character 'e' is not found in the *five* chars
    // of input text.
    // The statements inside will end up replacing garbage values with 'e'
    // until an 'e' is found, which might never happen.
    // In my case, it aborts with this error msg:
    //    *** stack smashing detected ***: terminated
    // which is entirely appropriate.
    while (*pointer != search_for) {
        *pointer = search_for; // this replaces all chars with 'e'
                               // which might not be the intention?
        pointer++;
    }
}
