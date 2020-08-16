int main() {
    int a = 5;
    /* int &b; */
    // ALTERNATIVE 1: Assuming b was meant to be a pointer
    //                (which *does* seem to make the most sense)
    int *b; // a pointer is declared with an asterisk, not an ampersand 
    b = &a; // b needs to point _to_ something (this dispels warnings)
    int *c;
    /* c = &b; */
    c = b; // assigning c (a pointer) to the value of b (a pointer)
           // does NOT require explicitly requesting the address with &
    /* *a = *b + *c; */
    a = *b + *c; // a is an integer value, not a pointer.
    /* &b = 2; */
    *b = 2; // I assume the value _at_ b will be set to 2.
            // The * operator is used to get/set the value
            // that a pointer points to. & gets the address.
}
