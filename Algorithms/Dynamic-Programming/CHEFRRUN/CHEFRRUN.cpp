//You're reading zeeshan_amjad's code
                     
#include <bits/stdc++.h>
                     
using namespace std;
                     
#define BOOSTIO ios_base::sync_with_stdio (0), cin.tie (0)
#define MOD 1e9 + 7
#define MAX 100000
#define LL long long
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
    int t, a[MAX], m[MAX], n, j, k;
    cin >> t;
    while (t--) {
        cin >> n;
        int ans[n] = {0}, l = k = 1, count = 0;
        FOR(i, 0, n) {
            cin >> a[i];
            m[i] = (i + a[i] + 1) % n;   
        }
        for (int i = 0; l <= n; i++)
            if (!ans[i]) {
                ans[i] = k;
                j = i;
                k += 1;
                while (m[j] >= i) {
                    j = m[j];
                    if (ans[j]) {
                        count += (ans[j] >= l) * (k - ans[j]);
                    break;
                }
                ans[j] = k;
                k += 1;
            }
            l = k;
        }
        cout << count << '\n';
    }
    return 0;
}     
