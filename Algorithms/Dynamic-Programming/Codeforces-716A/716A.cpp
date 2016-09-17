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
    int n, c, count = 1;
    cin >> n >> c;
    int a[n + 2];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (!i)
            continue;
        if (a[i] - a[i - 1] > c)
            count = 1;
        else
            count++;
    }
    cout << count;
    return 0;
}
