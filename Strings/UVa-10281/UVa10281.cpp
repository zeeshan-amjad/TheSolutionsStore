#include <iostream>
#include <iomanip>
#include <string>
#define FOR(i, a, b) for(int i = a; i < b; ++i)

using namespace std;

int conv (string s);
int toSec (string s);

int main () {
    string s, r;
    int cur_sec = 0, sec = 0;
    float cur_speed = 0.0, distance = 0.0;
    getline (cin, s);
    while (!cin.eof()) {
        distance += (toSec (s.substr (0, 8)) - cur_sec) * cur_speed / 1000.0;
        cur_sec = toSec (s.substr (0, 8));
        if (s.size() > 8)
            cur_speed = (5.0 / 18) * conv (s.substr (9, s.size() - 9));
        else
            cout << s << ' ' << fixed << setprecision (2) << distance << " km\n";
        getline (cin, s);
    }
    return 0;
}

int conv (string s) {
    int res = 0, len = s.size();
    FOR(i, 0, len)
        res = res * 10 + s[i] - '0';
    return res;
}

int toSec (string s) {
    return ((conv (s.substr (0, 2)) * 3600) + (conv (s.substr (3, 2)) * 60) + conv (s.substr (6, 2)));
}
