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
    int n;
    string s;
    cin >> n >> s;
    if (n == 12 && s[0] == '0' && s[1] == '0')
        s[1] = '1';
    if (n == 12 && s[0] > '1') {
        if (s[1] == '0')
            s[0] = '1';
        else
            s[0] = '0';
    }
    if (n == 12 && s[0] == '1' && s[1] > '2')
        s[0] = '0';
    if (n == 24 && s[0] > '2')
        s[0] = '0';
    if (n == 24 && s[0] == '2' && s[1] > '3')
        s[0] = '0';
    if (s[3] > '5')
        s[3] = '0';
    cout << s;
    return 0;
}
