#include "../std_lib_facilities.h"

struct Reading {
    int hour;
    double temperature;
};

int main() {
    vector<Reading> temps;
    int hour;
    double temperature;

    // read file in its own scope
    {
        ifstream ist{ "temps.txt" };
        if (!ist) error("error opening file");
        while (ist >> hour >> temperature) {
            if (hour < 0 || 23 < hour) error("hour out of range");
            temps.push_back(Reading{ hour, temperature });
        }
        // implicit file close when out of scope
    }

    for (const Reading& temp : temps)
        cout << "Hour: " << temp.hour
        << ", Temp: " << temp.temperature << endl;
}
