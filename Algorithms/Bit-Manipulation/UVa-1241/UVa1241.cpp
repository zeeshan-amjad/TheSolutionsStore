#include <iostream>
using namespace std;

int st[2047], ans;

int buildSegmentTree (bool *a, int l, int r, int i) {
    if (l == r)
        return (st[i] = a[l]);
    int mid = (l + r) / 2;
    st[i] = (buildSegmentTree (a, l, mid, i * 2 + 1)) & (buildSegmentTree (a, mid + 1, r, i * 2 + 2));
    return st[i];
}

int solve (int l, int r, int i) {
    if (l == r)
        return 0;
    int mid = (l + r) / 2;
    ans += st[i * 2 + 1] ^ st[i * 2 + 2];
    solve (l, mid, i * 2 + 1);
    solve (mid + 1, r, i * 2 + 2);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
	    int n, m;
	    cin >> n >> m;
	    bool a[(1 << n) + 1] = {0};
	    for (int i = 0; i < m; ++i) {
	        int p;
	        cin >> p;
	        a[p - 1] = 1;
	    }
	    buildSegmentTree (a, 0, (1 << n) - 1, 0);
	    solve(0, (1 << n) - 1, 0);
	    cout << ans << '\n';
	    ans = 0;
	}
	return 0;
}
