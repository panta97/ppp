#include "./../std_lib_facilities.h"

void number_to_string()
{
    vector<string> s_numbers = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int number;
    while (cin >> number)
    {
        if (number > s_numbers.size() - 1)
            cout << "bad input" << '\n';
        else
            cout << s_numbers[number] << '\n';
    }
}

// void string_to_number() {

// }

// int main()
// {
// }
