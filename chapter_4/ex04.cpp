#include "./../std_lib_facilities.h"

int main()
{
    string reply;
    vector<int> range = {1, 100};
    cout << "Think of a number from 1 to 100\n";
    cout << "Press (enter) when you're ready\n";
    cin.ignore();
    for (int i = 0; i < 7; i++)
    {
        const int guess = (range[1] - range[0]) / 2 + range[0];
        cout << "Is your number less than or equal to: " << guess << '\n';
        cout << "Type (y) for yes and (n) for no: ";
        cin >> reply;
        // update max value
        if (reply == "y")
            range[1] = guess;
        // update min value
        else if (reply == "n")
            range[0] = guess + 1;
        if (range[0] == range[1])
        {
            cout << "Your number is: " << range[0];
            break;
        }
    }
}
