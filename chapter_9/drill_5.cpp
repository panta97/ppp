#include "../std_lib_facilities.h"

enum class Month {
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

Month operator++(Month& m) {
    m = (m == Month::dec) ? Month::jan : Month(int(m) + 1);
    return m;
}


class Date {
public:
    int y, d;
    Month m;
public:
    Date(int y, Month m, int d);
    void add_days(int n);
    void add_months(int n);
    void add_years(int n);
    int year() const { return y; }
    Month month() const { return m; }
    int day() const { return d; }
};


bool is_valid_date(const Date& date) {
    if (1 > date.year()) return false;
    if (Month::jan > date.month() || date.month() > Month::dec) return false;
    switch (date.month())
    {
    case Month::feb:
        if (date.year() % 4 == 0) { // leap year
            if (1 > date.day() || date.day() > 29) return false;
        }
        else {
            if (1 > date.day() || date.day() > 28) return false;
        }
        break;
    case Month::apr:case Month::jun:case Month::sep:case Month::nov:
        if (1 > date.day() || date.day() > 30) return false;
        break;
    case Month::jan:case Month::mar:case Month::may:
    case Month::jul:case Month::aug:case Month::oct:case Month::dec:
        if (1 > date.day() || date.day() > 31) return false;
        break;
    }
    return true;
}

Date::Date(int yy, Month mm, int dd) :
    y{ yy }, m{ mm }, d{ dd } {
    if (!is_valid_date(*this)) error("not a valid date");
}

void Date::add_days(int n) {
    while (n > 0) {
        switch (m)
        {
        case Month::feb:
            if (y % 4 == 0) { // leap year
                if (1 <= d && d < 29) d++;
                else {
                    d = 1;
                    ++m;
                }
            }
            else {
                if (1 <= d && d < 28) d++;
                else {
                    d = 1;
                    ++m;
                }
            }
            break;
        case Month::apr:case Month::jun:case Month::sep:case Month::nov:
            if (1 <= d && d < 30) d++;
            else {
                d = 1;
                ++m;
            }
            break;
        case Month::jan:case Month::mar:case Month::may:case Month::jul:case Month::aug:case Month::oct:
            if (1 <= d && d < 31) d++;
            else {
                d = 1;
                ++m;
            }
            break;
        case Month::dec:
            if (1 <= d && d < 31) d++;
            else {
                d = 1;
                m = Month::jan;
                y++;
            }
            break;
        }
        n--;
    }
}

void Date::add_months(int n) {
    const int months = 12;
    int new_month = (int(m) + n) % months;
    m = Month(new_month);
    y += (n / months);
    switch (m)
    {
    case Month::feb:
        if (y % 4 == 0) { // leap year
            if (d > 29) d = 29;
        }
        else {
            if (d > 28) d = 28;
        }
        break;
    case Month::apr:case Month::jun:case Month::sep:case Month::nov:
        if (d > 30) d = 30;
        break;
    case Month::jan:case Month::mar:case Month::may:
    case Month::jul:case Month::aug:case Month::oct:case Month::dec:
        if (d > 31) d = 31;
        break;
    }
}

void Date::add_years(int n) {
    y += n;
}

void print_date(const Date& date) {
    cout << "Y: " << date.year() << ", M: " << int(date.month()) << ", D: " << date.day() << endl;
}

int main() {
    Date today(2020, Month::mar, 31);
    today.add_months(1);
    today.add_days(1665);
    print_date(today);
}
