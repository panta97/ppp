#include "../std_lib_facilities.h"


int main() {
    cout << "Please enter input file name: ";
    string iname;
    cin >> iname;
    ifstream ist{ iname };
    if (!ist) error("can't open input file ", iname);

    string content;
    ist >> content;
    cout << content;
}
