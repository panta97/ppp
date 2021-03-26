#include "./../std_lib_facilities.h"

double get_median(vector<double> vect)
{
    sort(vect);
    // if length is odd
    const int middle_index = vect.size() / 2;
    if (vect.size() & 1)
        return vect[middle_index];
    else
        return (vect[middle_index - 1] + vect[middle_index]) / 2;
}

int main()
{
    vector<double> vals;
    for (double temp; cin >> temp;)
    {
        vals.push_back(temp);
        // cout << temp << '\n';
    }
    cout << "--------------------\n";
    cout << "The median is: " << get_median(vals) << '\n';
}
