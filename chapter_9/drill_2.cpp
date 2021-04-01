#include "../std_lib_facilities.h"

struct Date {
    int y, m, d;
    Date(int y, int m, int d);
    void add_days(int n);
};

bool is_valid_date(const Date& date) {
    if (1 > date.y) return false;
    if (1 > date.m || date.m > 12) return false;
    switch (date.m)
    {
    case 2:
        if (date.y % 4 == 0) { // leap year
            if (1 > date.d || date.d > 29) return false;
        }
        else {
            if (1 > date.d || date.d > 28) return false;
        }
        break;
    case 4:case 6:case 9:case 11:
        if (1 > date.d || date.d > 30) return false;
        break;
    case 1:case 3:case 5:case 7:case 8:case 10:case 12:
        if (1 > date.d || date.d > 31) return false;
        break;
    }
    return true;
}

Date::Date(int yy, int mm, int dd) :
    y{ yy }, m{ mm }, d{ dd } {
    if (!is_valid_date(*this)) error("not a valid date");
}

void Date::add_days(int n) {
    while (n > 0) {
        switch (m)
        {
        case 2:
            if (y % 4 == 0) { // leap year
                if (1 <= d && d < 29) d++;
                else {
                    d = 1;
                    m++;
                }
            }
            else {
                if (1 <= d && d < 28) d++;
                else {
                    d = 1;
                    m++;
                }
            }
            break;
        case 4:case 6:case 9:case 11:
            if (1 <= d && d < 30) d++;
            else {
                d = 1;
                m++;
            }
            break;
        case 1:case 3:case 5:case 7:case 8:case 10:
            if (1 <= d && d < 31) d++;
            else {
                d = 1;
                m++;
            }
            break;
        case 12:
            if (1 <= d && d < 31) d++;
            else {
                d = 1;
                m = 1;
                y++;
            }
            break;
        }
        n--;
    }
}

void print_date(const Date& date) {
    cout << "Y: " << date.y << ", M: " << date.m << ", D: " << date.d << endl;
}

int main() {
    Date today(2021, 2, 28);
    today.add_days(1665);
    print_date(today);
}
