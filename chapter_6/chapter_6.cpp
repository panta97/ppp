#include "./../std_lib_facilities.h"

int main()
{
    cout << "Please enter expression (we can handle +, –, *, and /)\n";
    cout << "add an x to end expression (e.g., 1+2*3x): ";
    int lval = 0;
    int rval;
    cin >> lval; // read leftmost operand
    if (!cin)
        error("no first operand");
    for (char op; cin >> op;)
    { // read operator and right-hand operand
        // repeatedly
        if (op != 'x')
            cin >> rval;
        if (!cin)
            error("no second operand");
        switch (op)
        {
        case '+':
            lval += rval;
            break;
        case '-':
            lval -= rval;
            break;
        case '*':
            lval *= rval;
            break;
        case '/':
            lval /= rval;

            break;
        default:
            cout << "Result: " << lval << '\n';
            keep_window_open();
            return 0;
        }
    }
    error("bad expression");
}
/*input
1+2*3
*/
