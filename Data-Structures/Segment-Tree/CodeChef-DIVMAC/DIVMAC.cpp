    #include <bits/stdc++.h>
    using namespace std;
     
    #define MAX 1000006
     
    int lpd[MAX], st[300005], a[100005];
     
    void buildsieve () {
        lpd[1] = 1;
        //int s = sqrt (MAX);
        for (int i = 2; i < MAX; i += 1)
            for (int j = i; j < MAX; j += i)
                if (!lpd[j])
                    lpd[j] = i;
    }
     
    int buildSegmentTree (int l, int r, int i) {
        if (l == r)
                return (st[i] = lpd[a[l]]);
        int mid = (l + r) / 2;
        st[i] = max (buildSegmentTree (l, mid, i * 2 + 1), buildSegmentTree (mid + 1, r, i * 2 + 2));
        return st[i];
    }
     
    int query (int l, int r, int s, int e, int i) {
        if (s >= l && e <= r)
            return st[i];
        if (s > r || e < l)
            return INT_MIN;
        int mid = (s + e) / 2;
        return max (query (l, r, s, mid, i * 2 + 1), query (l, r, mid + 1, e, i * 2 + 2));
    }
     
    void update (int l, int r, int s, int e, int i) {
        if(s > e || s > r || e < l)
    		return;
    	if (s != e && s >= l && e <= r && st[i] == 1)
    	    return;
        if(s == e) {
        		a[s] = a[s] / lpd[a[s]];
        		st[i] = lpd[a[s]];
        		return;
    	}
    	int mid = (s + e) / 2;
    	update(l, r, s, mid, i * 2 + 1); 
    	update(l, r, mid + 1, e, i * 2 + 2); 
        st[i] = max (st[i * 2 + 1], st[i * 2 + 2]);    
    }
     
    int main () {
        ios_base::sync_with_stdio (0), cin.tie (0);
        buildsieve ();
        int t;
        cin >> t;
        while (t--) {
            int n, m;
            cin >> n >> m;
            for (int i = 0; i < n; ++i)
                cin >> a[i];
            buildSegmentTree (0, n - 1, 0);
            for (int i = 0; i < m; ++i) {
                int c, l, r;
                cin >> c >> l >> r;
                if (c) 
                    cout << query (l - 1, r - 1, 0, n - 1, 0) << ' ';
                else 
                    update (l - 1, r - 1, 0, n - 1, 0);
            }
            cout << '\n';
        }
        return 0;
    }  
