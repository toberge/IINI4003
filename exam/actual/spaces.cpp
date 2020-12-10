#include <string>
#include <iostream>

// Note: I assume that Inspera actually has syntax hightlighting for C++.
//       It would make sense to enable it, right?

using namespace std;

/// Take a string literal (an rvalue),
/// return a *new* string where ␣ (space) is replaced with with _
/// (if variants 1 and 2 had the same name,
///  this function signature would *not* cause a compilation error,
///  while const string &str would cause ambiguity.
///  It would work perfectly fine in this case, though.)
string spaces_to_underscore1(const string &&str) {
    string underscored;
    underscored.reserve(str.size());
    // Yes, std::string *does* have a replace() method
    // - but then, what would be the point of this task if I didn't do it "by hand"?
    for (auto chr : str) {
        if (chr == ' ') {
            underscored += '_';
        } else {
            underscored += chr;
        }
    }
    return underscored;
}

/// Take a string reference, replace ␣ (space) with _, return nothing
/// (that is, *mutate* the string)
void spaces_to_underscore2(string &str) {
    for (int i = 0; i < str.length(); i++)
        if (str[i] == ' ')
            str[i] = '_';
}

// Constant for default value
char underscore_value = '_';
char *UNDERSCORE = &underscore_value;

/// Take a string literal, replace ␣ (space) with _ or a *specified* character
/// Required a constant char pointer since a char * is passed to it
/// and I wanted to get away with writing just *one* function.
string spaces_to_underscore_or_character(const string &&str, char *replace=UNDERSCORE) {
    if (!replace) replace = UNDERSCORE; // absolutely default to _
    string underscored;
    underscored.reserve(str.size());
    // Again... Yes, there *is* a std::string::replace() method
    for (auto chr : str) {
        if (chr == ' ') {
            underscored += replace;
        } else {
            underscored += chr;
        }
    }
    return underscored;
}

int main() {
    // Requires a function that handles rvalues -> pure
    cout << spaces_to_underscore1("this is a string") << endl;

    string str("this is a string");
    // Requires lvalue mutation -> impure
    spaces_to_underscore2(str);
    cout << str << endl;

    char chr('+');
    // Again just some pure rvalue function... but a char * is passed in the first two calls.
    cout << spaces_to_underscore_or_character("this is a string", &chr) << endl;
    cout << spaces_to_underscore_or_character("this is a string", nullptr) << endl;
    cout << spaces_to_underscore_or_character("this is a string") << endl;
}
