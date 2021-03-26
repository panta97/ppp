#include "./../std_lib_facilities.h"

double get_total(vector<double> vect)
{
    double sum = 0;
    for (double item : vect)
        sum += item;
    return sum;
}

double get_mean(vector<double> vect)
{
    return get_total(vect) / vect.size();
}

vector<double> read_get_sequence()
{
    vector<double> sequence;
    for (double temp; cin >> temp;)
        sequence.push_back(temp);
    return sequence;
}

vector<double> get_distance(vector<double> vect)
{
    vector<double> distance_vals;
    for (int i = 0; i < vect.size() - 1; i++)
        distance_vals.push_back(abs(vect[i] - vect[i + 1]));
    return distance_vals;
}
int main()
{
    vector<double> vals;
    vals = read_get_sequence();
    vals = get_distance(vals);

    sort(vals);
    cout << "total distance: " << get_total(vals) << '\n'
         << "smallest distance: " << vals[0] << '\n'
         << "largest distance: " << vals[vals.size() - 1] << '\n'
         << "mean distance: " << get_mean(vals) << '\n';
}
