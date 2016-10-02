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
 
bool isvowel (char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
} 
 
int main () {
    BOOSTIO;
    int n, a[101];
    char c;
    cin >> n;
    FOR(i, 0, n)
        cin >> a[i];
    string s;
    getline(cin, s);
    FOR(i, 0, n) {
        int v = 0;
        getline (cin, s);
        int l = s.size();
        FOR(i, 0, l)
            if (isvowel (s[i]))
                v++;
        if (v != a[i]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
