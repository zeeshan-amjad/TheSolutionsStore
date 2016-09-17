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

bool solve (char *s, int p) {
    int f = 0; 
    bool a[27] = {0};
    FOR(i, p, p + 26) {
        if (a[s[i] - 65]) {
            f = i;
            break;
        }
        if (s[i] != '?')
            a[s[i] - 65] = 1;
    }
    int j = 0;
    if (!f) {
        FOR(i, p, p + 26) 
            if (s[i] == '?') {
                while (a[j])
                    j++;
                s[i] = 'A' + j;
                j++;
            }
    }
    if (s[p] == '?')
        s[p] = 'A';
    return f == 0;    
} 
 
int main () {
    BOOSTIO;
    char s[50005];
    cin >> s;
    int l = strlen (s), c = 0;
    FOR(i, 0, l - 26 + 1) 
        if (solve (s, i))
            c = 1;
    rFOR(i, l - 1, l - 1 - 26)
        if (s[i] == '?')
            s[i] = 'A';
    if (c)
        cout << s;
    else
        cout << -1;
    return 0;
}
