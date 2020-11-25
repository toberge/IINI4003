#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

class File {
private:
    static const unordered_map<string, string> types;
    // TODO: make 'em const (i.e., figure out the initialization)
    string filename;
    string filetype;
public:
    File(const string &filename_) {
        auto split = filename_.rfind(".");
        if (split == string::npos) {
            filename = filename_;
            filetype = "";
        } else {
            filename = filename_.substr(0, split);
            filetype = filename_.substr(split+1);
        }
    }

    string type() const {
        if (types.find(filetype) != types.end()) {
            return types.find(filetype)->second;
        } else {
            return "unknown";
        }
    }
};

const unordered_map<string, string> File::types = {
    {"pdf", "Portable Document Format"},
    {"txt", "Plain text"},
};

// to get a pointer.... Pointless, if you ask me.
File *file(string filename) {
    File *f = new File(filename);
    return f;
}

int main() {
    auto f1 = file("test.pdf");
    cout << f1->type() << endl;
    auto f2 = file("test.txt");
    cout << f2->type() << endl;
    auto f3 = file("test.dat");
    cout << f3->type() << endl;
    auto f4 = file("test");
    cout << f4->type() << endl;
}
