#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string text = "I was born on march 8 1997";
    vector<int> ns;
    istringstream is{ text };
    while (!is.eof()) {
        int temp;
        if (is >> temp) ns.push_back(temp);
        else {
            is.clear();
            char c;
            is >> c; //throw away
        }
    }

    for (int& n : ns)
        cout << n << endl;

}
