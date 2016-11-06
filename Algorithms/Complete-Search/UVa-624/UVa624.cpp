#include <iostream>
#include <climits>
using namespace std;

int n, a[21], m, ans;

void solve (int val, int p, int mask) {
	if (val < 0)
		return;
	if (val < m) {
		m = val;
		ans = mask;
	}
	if (p == n)
		return;

	solve (val - a[p], p + 1, mask | (1 << p));
	solve (val, p + 1, mask);
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (NULL);
	int v;
	while (cin >> v >> n) {
		m = INT_MAX;
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		solve (v, 0, 0);
		int sum = 0;
		for (int i = 0; i < n; ++i)
			if (ans & (1 << i)) {
				cout << a[i] << ' ';
				sum += a[i];
			}
		cout << "sum:" << sum << '\n';
	}
	return 0;
}
