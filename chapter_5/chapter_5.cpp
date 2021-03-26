#include "./../std_lib_facilities.h"

int main()
{
    constexpr double MAX_TEMP = 136;
    constexpr double MIN_TEMP = -126;

    vector<double> temps;
    for (double temp; cin >> temp;)
        temps.push_back(temp);
    double sum = 0;
    double high_temp = MAX_TEMP;
    double low_temp = MIN_TEMP;
    for (int x : temps)
    {
        if (x > high_temp)
            high_temp = x;
        if (x < low_temp)
            low_temp = x;
        sum += x;
    }
    cout << "High temperature: " << high_temp << '\n';
    cout << "Low temperature: " << low_temp << '\n';
    cout << "Average temperature: " << sum / temps.size() << '\n';
}
