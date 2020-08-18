#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    // Task a)
    string word1, word2, word3;
    cout << "Three words, please: ";
    cin >> word1 >> word2 >> word3;
    cin.get(); // remove newline

    // Task b)
    ostringstream oss;
    oss << word1 << " " << word2 << " " << word3;
    string sentence = oss.str();
    cout << "You wrote: " << sentence << endl;

    // Task c)
    string words[] = { word1, word2, word3 };
    for (auto word : words) {
        cout << word << " is of length " << word.length() << endl;
    }
    cout << "The entire sentence is of length "
         << sentence.length() << endl;

    // Task d)
    string sentence2 = sentence; // not a reference -> a copy.

    // Task e) -> 10-12 is an index range, it seems
    if (sentence2.size() > 10) {
        for (int i = 10; i <= 12 && i < (int) sentence2.size(); i++) {
            sentence2[i] = 'x';
        }
        cout << sentence << endl
             << sentence2 << endl;
    } else {
        cout << "This requires a sentence longer than 10 chars" << endl;
    }

    // Task f)
    // it should be impossible to have < 5 chars in the sentence
    // when there are three words separated by two spaces.
    string sentence_start = sentence.substr(0, min(5, (int)sentence.length()));
    cout << "First 5 chars: " << sentence_start << endl;

    // Task g)
    cout << "Setningen inneholder "
         << (sentence.find("hallo") == string::npos ? "ikke " : "")
         << "'hallo'" << endl;

    // Task h)
    int start_index = 0;
    size_t found_index = -1;
    // Search for "er", use location to update start of next search
    while ((found_index = sentence.find("er", start_index)) != string::npos) {
        cout <<  "Found 'er' at index " << found_index
             << " (" << sentence.substr(found_index, 2) << ")" << endl;
        start_index = found_index + 1;
    }
}
