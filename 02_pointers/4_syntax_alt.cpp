int main() {
    int a = 5;
    /* int &b; */
    // ALTERNATIVE 2: b is a reference
    int &b = a; // if b is a reference, must be a reference to a
    int *c;
    c = &b; // (now the ampersand makes sense)
    /* *a = *b + *c; */
    a = b + *c; // b is a reference, a is a variable
                // in this case it is equivalent to `a += *c`
    b = 2; // again, b is a reference
}
