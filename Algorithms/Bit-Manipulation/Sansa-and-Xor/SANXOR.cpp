#include <bits/stdc++.h>

#define MOD 1000000007
#define ll long long
#define ld long double
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define rFOR(i, a, b) for(int i = a; i > b; i--)
#define PAIR pair <int, int>
#define PQ priority_queue <ld>
#define MAP map <int, int>

using namespace std;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n, x = 0, val;
        cin >> n;
        FOR(i, 1, n + 1) {
            cin >> val;
            if ((i * (n - i + 1)) % 2)
                x ^= val;
        }
        cout << x << '\n';
    }
    return 0;
}
