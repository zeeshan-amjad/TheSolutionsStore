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
typedef map <string, int> Map;
typedef stack <int> Stack;
typedef queue <int> Queue;
typedef priority_queue <int> PQ;
 
int main () {
    BOOSTIO;
    int n, c = 0;
    string s;
    cin >> n >> s;
    Vector v;
    //bool flag = false;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'W') {
            if (c)
                v.PB (c);
            c = 0;
            continue;
        }
        //flag = true;
        c++;
        if (i == s.size() - 1 && c)
            v.PB (c);
    }
    int l = v.size();
    cout << l << '\n';
    for (int i = 0; i < l - 1; ++i) 
        cout << v[i] << ' ';
    if (l)
        cout << v[l - 1];
    return 0;
}
