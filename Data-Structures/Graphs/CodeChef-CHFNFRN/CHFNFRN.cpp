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
        int t;
        cin >> t;
        while (t--) {
            int n, m;
            cin >> n >> m;
            int graph[n + 2][n + 2] = {0}, table[n + 2] = {0};
            bool visited[n + 2] = {0}, ans = true;
            for (int i = 0; i < m; ++i) {
                int l, r;
                cin >> l >> r;
                graph[l][r] = graph[r][l] = 1;
            }
            Queue q;
            q.push (1);
            table[1] = 1;
            int j = 1;
            while (j <= n && ans) {
                if (q.empty()) {
                    while (j <= n && table[j])
                        j++;
                    if (j > n)
                        break;
                    q.push (j);
                    table[j] = 1;
                }
                int t = q.front(), dest = 3 - table[t];
                visited[t] = true;
                q.pop();
                for (int i = 1; i <= n; ++i)
                    if (i != t && !graph[t][i]) {
                        if (table[i] && table[i] != dest) {
                            ans = false;
                            break;
                        }
                        table[i] = dest;
                        if (!visited[i])
                            q.push (i);
                    }
            }
            if (ans)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        return 0;
    } 
