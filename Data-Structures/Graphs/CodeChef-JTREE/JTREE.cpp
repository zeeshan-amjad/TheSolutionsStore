    #include <iostream>
    #include <vector>
    #include <cstring>
    using namespace std;
     
    #define MAX 10000000000000001LL
    #define ll long long
     
    int n, m;
    ll cost[100005], st[400005];
    vector <int> graph[100005];
    vector <pair <int, int>> tickets[100005];
    bool visited[100005];
     
    ll buildSegmentTree (int l, int r, int i) {
        if (l == r)
            return (st[i] = cost[l]);
        int mid = (l + r) / 2;
        st[i] = min (buildSegmentTree (l, mid, i * 2 + 1), buildSegmentTree (mid + 1, r, i * 2 + 2));
        return st[i];
    }
     
    ll query (int l, int r, int s, int e, int i) {
        if (s >= l && e <= r) 
            return st[i];
        if (s > r || e < l)
            return MAX;
        int mid = (s + e) / 2;
        return min (query (l, r, s, mid, i * 2 + 1), query (l, r, mid + 1, e, i * 2 + 2));
    }
     
    void update (int l, int r, int s, int e, int i, ll val) {
        if(s > e || s > r || e < l)
    		return;
        if(s == e && s == l) {
        	st[i] = val;
        	return;
    	}
        int mid = (s + e) / 2;
        update(l, r, s, mid, i * 2 + 1, val); 
        update(l, r, mid + 1, e, i * 2 + 2, val); 
        st[i] = min (st[i * 2 + 1], st[i * 2 + 2]);    
    }
     
    void dfs (int node, int dist) {
        int s = tickets[node].size();
        ll m = MAX;
        for (int i = 0; i < s; ++i)
            m = min (m, tickets[node][i].second + query (max (0, dist - tickets[node][i].first), dist - 1, 0, n - 1, 0));
        cost[node] = m * (node != 1);
        update (dist, dist, 0, n - 1, 0, cost[node]);
        int l = graph[node].size();
        visited[node] = 1;
        for (int i = 0; i < l; ++i) 
            if (!visited[graph[node][i]]) {
                dfs (graph[node][i], dist + 1);
                update (dist + 1, dist + 1, 0, n - 1, 0, MAX);
            }
    }
     
    int main () {
        ios_base::sync_with_stdio (false), cin.tie (NULL);
        cin >> n >> m;
        for (int i = 0; i <= n; ++i)
            cost[i] = MAX;
        buildSegmentTree (0, n - 1, 0);
        for (int i = 0; i < n - 1; ++i) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back (b);
            graph[b].push_back (a);
        }
        for (int i = 0; i < m; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            tickets[a].push_back ({b, c});
        } 
        dfs (1, 0);
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            cout << cost[n] << '\n';
        }
        return 0;
    } 
