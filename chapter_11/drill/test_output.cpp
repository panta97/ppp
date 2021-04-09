#include "../../std_lib_facilities.h"

int main() {
    int birth_year;
    cout << "type your birth year: ";
    cin >> birth_year;

    cout << "DEC:" << '\t' << birth_year << endl;
    cout << "HEX:" << hex << '\t' << birth_year << endl;
    cout << "OCT:" << oct << '\t' << birth_year << endl;

    cout << dec << 24 << endl;

    int a, b, c, d;
    cin >> a >> oct >> b >> hex >> c >> d;
    cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';

    double n = 1234567.89;
    cout << defaultfloat << n << endl;
    cout << fixed << n << endl;
    cout << scientific << n << endl;
}
