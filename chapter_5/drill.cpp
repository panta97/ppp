#include "./../std_lib_facilities.h"

int main()
try
{
    cout << "1. Success!\n";
    cout << "2. Success!\n";
    cout << "3. Success" << "!\n";
    cout << "4. success" << '\n';
    int res = 7; vector<int> v(10); v[5] = res; cout << "5. Success!\n";
    v[5] = 6; if (v[5]!=7) cout << "6. Success!\n";
    if (v[5] == 6) cout << "7. Success!\n"; else cout << "Fail!\n";
    bool c = false; if (!c) cout << "8. Success!\n"; else cout << "Fail!\n";
    string s = "ape"; c = "fool">s; if (c) cout << "9. Success!\n";
    s = "ape"; if (s=="ape") cout << "10. Success!\n";
    s = "ape"; if (s!="fool") cout << "11. Success!\n";
    s = "ape"; if ((s+"fool") == "apefool") cout << "12. Success!\n";
    vector<char> v1(5); for (int i=0; i<v1.size(); ++i){}; cout << "13. Success!\n";
    vector<char> v2(5); for (int i=0; i<v2.size(); ++i){}; cout << "14. Success!\n";
    s = "15. Success!\n"; for (int i=0; i<s.size(); ++i) cout << s[i];
    if (true) cout << "16. Success!\n"; else cout << "Fail!\n";
    int x = 2000; c = x; if (c) cout << "17. Success!\n";
    s = "18. Success!\n"; for (int i=0; i<s.size(); ++i) cout << s[i];
    for (int i=v.size()-1; i<v.size(); ++i) cout << "19. Success!\n";
    int i=0; int j = 9; while (i<j) ++i; if (j<=i) cout << "20. Success!\n";
    x = 2; double d = 5/(x + 3); if (d==0.5*x) cout << "21. Success!\n";
    string s2 = "22. Success!\n"; for (int i=0; i<s2.size(); ++i) cout << s2[i];
    i=0; while (i<10) ++i; if (j<i) cout << "23. Success!\n";
    x = 4; double d2 = 5.0/(x - 2); if (d2==2*x-5.5) cout << "24. Success!\n";
    cout << "25. Success!\n";

    // keep_window_open();
    return 0;
}
catch (exception &e)
{
    cerr << "error: " << e.what() << '\n';
    keep_window_open();
    return 1;
}
catch (...)
{
    cerr << "Oops: unknown exception!\n";
    keep_window_open();
    return 2;
}
