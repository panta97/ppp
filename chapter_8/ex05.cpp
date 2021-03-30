#include "../std_lib_facilities.h"

vector<int> reverse(vector<int> vals) {
    vector<int> reversed;
    for (int i = vals.size() - 1; i >= 0; i--)
        reversed.push_back(vals[i]);
    return reversed;
}

void reverse_r(vector<int>& vals) {
    for (int s = 0, e = vals.size() - 1; s < vals.size() / 2; s++, e--)
        swap(vals[s], vals[e]);
}

void print(const vector<int>& vals) {
    for (const int& v : vals)
        cout << v << endl;
}

int main() {
    // vector<int> vals = { 1,2,3,4,5 };
    // vector<int> vals_r = reverse(vals);
    // print(vals);
    // print(vals_r);

    vector<int> vals = { 10, 9, 8, 7 };
    vector<int>& vals2 = vals;
    reverse_r(vals);
    print(vals);
    print(vals2);
}
