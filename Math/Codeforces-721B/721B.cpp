//You're reading zeeshan_amjad's code
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define BOOSTIO ios_base::sync_with_stdio (0), cin.tie (0)
#define MAX 100005
#define MOD 1000000007
#define LL int64_t
#define LD long double
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define rFOR(i, a, b) for(int i = a; i > b; --i)
#define PB push_back
 
typedef vector <int> Vector;
typedef pair <int, int> Pair;
typedef map <int, int> Map;
typedef stack <int> Stack;
typedef queue <int> Queue;
typedef priority_queue <int> PQ;
 
int main () {
    BOOSTIO;
    int n, k, c = 0, p, l = 0, r = 0;
    string s, pass;
    cin >> n >> k;
    Map m;
    FOR(i, 0, n) {
        cin >> s;
        m[s.size()] += 1;
    }
    cin >> pass;
    p = pass.size();
    Map::iterator it;
    for (it = m.begin(); it != m.end(); ++it) {
        if (it->first < p) {
            l += it->second + ((c + it->second) / k) * 5;
            c = (c + it->second) % k;
            r = l;
            continue;
        }
        l += 1;
        r += it->second + ((int)ceil (((c + it->second) / (float)k)) - 1) * 5;
        cout << l << ' ' << r;
        break;
    }
    return 0;
}
