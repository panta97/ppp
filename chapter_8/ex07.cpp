#include "../std_lib_facilities.h"



int main() {
    vector<string> names = { "Jorge", "Karen", "Roosevelt", "Heydee", "Gabriel" };
    vector<int> ages;
    for (string& name : names) {
        cout << name << "'s age: ";
        int age;
        cin >> age;
        ages.push_back(age);
    }

    cout << "----------" << endl;
    for (int i = 0; i < names.size();i++) {
        cout << names[i] << "'s age is " << ages[i] << endl;
    }

    cout << "----------" << endl;
    vector<string> names_c = names;
    vector<int> ages_c;
    sort(names);

    for (int i = 0; i < names.size();i++)
        for (int j = 0; j < names_c.size(); j++)
            if (names[i] == names_c[j]) {
                ages_c.push_back(ages[j]);
                break;
            }

    for (int i = 0; i < names.size();i++) {
        cout << names[i] << "'s age is " << ages_c[i] << endl;
    }
}
