#include "../std_lib_facilities.h"

struct Point {
    int x = 0;
    int y = 0;
};

istream& operator>>(istream& is, Point& p) {
    // start comma end
    char s, c, e;
    int x, y;
    is >> s >> x >> c >> y >> e;
    if (!is) return is;
    if (s != '(' || c != ',' || e != ')') {
        // is.clear(ios_base::failbit);
        is.clear();
        return is;
    }
    p.x = x;
    p.y = y;
    return is;
}

ostream& operator<<(ostream& os, const Point& p) {
    os << '(' << p.x << ',' << p.y << ')';
    return os;
}

int main() {
    vector<Point> original_points{ 7 };
    cout << "Please enter " << original_points.size() << " point(s) " << endl
        << "in this format (x,y)" << endl;

    // cin.exceptions(cin.exceptions() | ios_base::badbit);
    for (Point& p : original_points) {
        cin >> p;
    }

    string filename = "mydata.txt";
    {
        ofstream ofs{ filename };
        for (const Point& p : original_points)
            ofs << p << endl;
    }

    vector<Point> processed_points;
    {
        ifstream ifs{ filename };
        for (Point p; ifs >> p;)
            processed_points.push_back(p);
    }
}
