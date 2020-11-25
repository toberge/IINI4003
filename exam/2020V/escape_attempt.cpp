#include <algorithm>
#include <iostream>
#include <string>

// Just an attempt at doing something *different*
// from what I did last time I had this kind of task.
// NB: This is *far* less efficient than the other solution.

using namespace std;

string &replace(string &str, const string target, const string replacer) {
    long pos = 0;
    while ((pos = str.find(target, pos)) != string::npos) {
        str.erase(pos, 1);
        str.insert(pos, replacer);
        pos += replacer.size();
    }
    return str;
}

// aha, it can be void and thus avoid the mixup with the other variant...
void escape(std::string &str) {
    replace(str, "&", "&amp;");
    replace(str, ">", "&gt;");
    replace(str, "<", "&lt;");
}

string escape(const string &str) {
    string tmp(str);
    return replace(replace(replace(tmp, "&", "&amp;"), ">", "&gt;"), "<", "&lt;");
}

int main() {
    cout << escape("Escape these symbols: <<&>>") << endl;
    string text("Escape these symbols as well: >>&<<");
    escape(text);
    cout << text << endl;
}
