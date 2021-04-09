#include "../std_lib_facilities.h"

int main() {
    istringstream iss;
    iss.str("some long input string");


    vector<string> words;
    for (string word; iss >> word;)
        words.push_back(word);

    for (const string& word : words)
        cout << word << endl;

}
