#include <iostream>
#include <climits>
#include <iomanip>
#include <cmath>

using namespace std;

int n, q;

int buildminSegmentTree (int *a, int l, int r, int *minst, int i) {
        if (l == r)
                return (minst[i] = a[l]);
        int mid = (l + r) / 2;
        minst[i] = min (buildminSegmentTree (a, l, mid, minst, i * 2 + 1), buildminSegmentTree (a, mid + 1, r, minst, i * 2 + 2));
        return minst[i];
}

int buildmaxSegmentTree (int *a, int l, int r, int *maxst, int i) {
        if (l == r)
                return (maxst[i] = a[l]);
        int mid = (l + r) / 2;
        maxst[i] = max (buildmaxSegmentTree (a, l, mid, maxst, i * 2 + 1), buildmaxSegmentTree (a, mid + 1, r, maxst, i * 2 + 2));
        return maxst[i];
}

int minquery (int *minst, int l, int r, int s, int e, int i) {
        if (s >= l && e <= r)
                return minst[i];
        if (s > r || e < l)
                return INT_MAX;
        int mid = (s + e) / 2;
        return max (maxquery (maxst, l, r, s, mid, i * 2 + 1), maxquery (maxst, l, r, mid + 1, e, i * 2 + 2));
}

int main () {
        cin >> n;
        int *a = new int[n + 1], size = 2 * (1 << ((int)ceil (log2(n)))) - 1;
        for (int i = 0; i < n; ++i)
                cin >> a[i];
        int *minst = new int[size], *maxst = new int[size];
        buildminSegmentTree (a, 0, n - 1, minst, 0);
        buildmaxSegmentTree (a, 0, n - 1, maxst, 0);
        cin >> q;
        while (q--) {
                int l, r, m, M, M1;
                cin >> l >> r;
                m = minquery (minst, l, r, 0, n - 1, 0), M = maxquery (maxst, l, r, 0, n - 1, 0);
                M1 = max (maxquery (maxst, 0, l - 1, 0, n - 1, 0), maxquery (maxst, r + 1, n - 1, 0, n - 1, 0));
                M1 = max (0, M1);
                float ans = m + max ((float)(M - m) / 2, (float)M1);
                cout << fixed << setprecision (1) << ans << '\n';
        }
        return 0;
}
