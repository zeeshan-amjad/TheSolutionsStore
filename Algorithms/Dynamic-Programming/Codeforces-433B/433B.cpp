#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long

using namespace std;

vector <ll> CUMLSUM (const vector <ll> &v) {
    vector <ll> temp;
    for (vector <ll>::const_iterator it = v.begin(); it != v.end(); ++it)
        if (it == v.begin())
            temp.push_back (*it);
        else
            temp.push_back (temp[temp.size() - 1] + *it);
    return temp;
}

int main () {
    int n;
    cin >> n;
    vector <ll> cost;
    for (int i = 0; i < n; ++i) {
        ll val;
        cin >> val;
        cost.push_back (val);
    }
    vector <ll> q1 = CUMLSUM (cost);
    sort(cost.begin(), cost.end());
    vector <ll> q2 = CUMLSUM (cost);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int c, l, r;
        cin >> c >> l >> r;
        ll a, b, ans;
        if (c == 1) {
            if (l - 2 < 0)
                a = 0;
            else 
                a = q1[l - 2];
            b = q1 [r - 1];
            ans = b - a;
            cout << ans << '\n';
        }
        else {
            if (l - 2 < 0)
                a = 0;
            else 
                a = q2[l - 2];
            b = q2[r - 1];
            ans = b - a;
            cout << ans << '\n';
        }
    }
    return 0;
}
