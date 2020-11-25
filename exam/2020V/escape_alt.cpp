#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string escape(const string &str) {
    string out;
    out.reserve(str.size());
    for (auto &c : str) {
        switch(c) {
            case '<':
                out += "&lt;";
                break;
            case '>':
                out += "&gt;";
                break;
            case '&':
                out += "&amp;";
                break;
            default:
                out += c;
                break;
        }
    }
    return out;
}

void escape(string &str) {
    for (size_t i = 0; i < str.size(); i++) {
        switch(str[i]) {
            case '<':
                str.replace(i, 1, "&");
                str.insert(i + 1, "lt;");
                i += 3;
                break;
            case '>':
                str.replace(i, 1, "&");
                str.insert(i + 1, "gt;");
                i += 3;
                break;
            case '&':
                str.insert(i + 1, "amp;");
                i += 4;
                break;
            default:
                i++;
                break;
        }
    }
}

int main() {
    cout << escape("Escape these symbols: <<&>>") << endl;
    std::string text("Escape these symbols as well: >>&<<");
    escape(text);
    cout << text << endl;
}
