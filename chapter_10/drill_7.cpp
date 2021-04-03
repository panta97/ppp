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

void print_points(const vector<Point>& points, const string& title) {
    cout << title << endl;
    for (const Point& p : points)
        cout << p << endl;
}

bool operator!=(const Point& lp, const Point& rp) {
    if (lp.x != rp.x || lp.y != rp.y) return true;
    return false;
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

    print_points(original_points, "original points");
    print_points(processed_points, "processed points");

    for (int i = 0; i < original_points.size(); i++)
        if (original_points[i] != processed_points[i])
            cout << "Something's Wrong" << endl;
}
