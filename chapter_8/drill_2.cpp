#include "../std_lib_facilities.h"

void swap_v(int a, int b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void swap_r(int& a, int& b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}
// void swap_cr(const int& a, const int& b) {
//     int temp;
//     temp = a;
//     a = b;
//     b = temp;
// }

void print(const int& a, const int& b) {
    cout << "val 1: " << a << ", val 2: " << b << endl;
}

int main() {
    int x = 7;
    int y = 9;
    swap_r(x, y);
    print(x, y);
    const int cx = 7;
    const int cy = 9;
    swap_v(cx, cy);
    print(cx, cy);
    double dx = 7.7;
    double dy = 9.9;
    swap_r(dx, dy);
    print(dx, dy);

}
