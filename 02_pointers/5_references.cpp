int main() {
    double number = 3.1425;
    double *number_ptr = &number; // pointer
    double &number_ref = number; // reference

    // three ways of setting the value:
    number = 2.718281828; // directly
    *number_ptr = 1.61803398875; // by pointer
    number_ref = 2.718281828; // by reference
}
