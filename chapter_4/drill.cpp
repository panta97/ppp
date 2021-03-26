#include "./../std_lib_facilities.h"

double get_m(double val, string unit)
{
    constexpr double m_cm = 0.01;
    constexpr double m_in = 0.0254;
    constexpr double m_ft = 0.3048;
    if (unit == "cm")
        return val * m_cm;
    else if (unit == "m")
        return val;
    else if (unit == "in")
        return val * m_in;
    else if (unit == "ft")
        return val * m_ft;
    return -1;
}

int main()
{
    string unit;
    double val;
    double smallest = 0, largest = 0;
    bool init = false;
    vector<double> vals_entered;
    while (cin >> val >> unit)
    {
        const double meters = get_m(val, unit);
        if (meters == -1)
        {
            cout << "bad input\n";
            continue;
        }

        vals_entered.push_back(meters);
        // init smallest and largest
        if (!init)
        {
            smallest = meters;
            largest = meters;
            init = true;
        }
        else
        {
            smallest = meters < smallest ? meters : smallest;
            largest = meters > largest ? meters : largest;
        }
        cout << "smallest so far " << smallest << "m\n";
        cout << "largest so far " << largest << "m\n";
    }

    sort(vals_entered);
    cout << "smallest value " << vals_entered[0] << "m\n";
    cout << "largest value " << vals_entered[vals_entered.size() - 1] << "m\n";
    double sum = 0;
    for (double val : vals_entered)
        sum += val;
    cout << "sum " << sum << "m\n";
}
