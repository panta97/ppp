#include "../std_lib_facilities.h"

struct Date {
    int y;
    int m;
    int d;
};

void print_date(const Date& date) {
    cout << "Y: " << date.y << ", M: " << date.m << ", D: " << date.d << endl;
}

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

Date add_day(Date date) {
    date.d++;
    return date;
}

int main() {
    Date today{ 1978, 6, 25 };
    cout << (is_valid_date(today) ? "valid" : "invalid") << endl;
    print_date(today);
    Date tomorrow = add_day(today);
    cout << (is_valid_date(tomorrow) ? "valid" : "invalid") << endl;
    print_date(tomorrow);
}
