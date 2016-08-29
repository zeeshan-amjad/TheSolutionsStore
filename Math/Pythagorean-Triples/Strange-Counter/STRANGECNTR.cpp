//You're reading zeeshan_amjad's code
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define BOOSTIO ios_base::sync_with_stdio (0), cin.tie (0)
#define MOD 1e9 + 7
#define LL long long
#define LD long double
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define rFOR(i, a, b) for(int i = a; i > b; --i)
#define PB push_back
 
typedef vector <int> Vector;
typedef pair <int, int> Pair;
typedef map <string, int> Map;
typedef stack <int> Stack;
typedef queue <int> Queue;
typedef priority_queue <int> PQ;;

int main () {
    BOOSTIO;
    LL t;
    cin >> t;
    LL n = (LL)log2 ((t + 2) / 3.0);
    LL x = 1 + 3 * (pow(2, n) - 1);
    cout << x + 2 - (t - x);
    return 0;
}

