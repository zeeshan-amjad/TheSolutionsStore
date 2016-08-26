#include <iostream>
#include <climits>
#include <cmath>
#define MAX 100005
#define LL long long

using namespace std;

int getmin (int *a, int i, int j) {
        if (i == -1)
                return j;
        if (j == -1)
                return i;
        if (a[i] < a[j])
                return i;
        return j;
}

int buildSegmentTree (int *a, int l, int r, int *st, int i) {
        if (l == r)
                return (st[i] = l);
        int mid = (l + r) / 2;
        st[i] = getmin (a, buildSegmentTree (a, l, mid, st, i * 2 + 1), buildSegmentTree (a, mid + 1, r, st, i * 2 + 2));
        return st[i];
}

int query (int *a, int *st, int l, int r, int s, int e, int i) {
        if (s >= l && e <= r)
                return st[i];
        if (s > r || e < l)
                return -1;
        int mid = (s + e) / 2;
        return getmin (a, query (a, st, l, r, s, mid, i * 2 + 1), query (a, st, l, r, mid + 1, e, i * 2 + 2));
}

LL getAns (int n, int *h, int *st, int l, int r) {
        if (l > r)
                return 0;
        if (l == r)
                return h[l];
        int p = query (h, st, l, r, 0, n - 1, 0);
        return max (((LL)r - l + 1) * h[p], max (getAns (n, h, st, l, p - 1), getAns (n, h, st, p + 1, r)));
}

int main () {
        int n, *h = new int[MAX], *st = new int [2 * (1 << 20) - 1];
        cin >> n;
        while (n) {
                for (int i = 0; i < n; ++i)
                        cin >> h[i];
                buildSegmentTree (h, 0, n - 1, st, 0);
                LL ans = getAns (n, h, st, 0, n - 1);
                cout << ans << '\n';
                cin >> n;
        }
        return 0;
}
