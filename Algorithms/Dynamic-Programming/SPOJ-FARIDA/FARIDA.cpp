#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL solve (int coins[], int n) {
	LL ans[n + 1] = {};
	for (int i = n - 1; i >= 0; --i) {
		if (i > n - 3) {
			if (i == n - 1)  
				ans[i] = coins[i];
			if (i == n - 2)
				ans[i] = max (coins[i], coins[i + 1]);
			continue;
		}
		ans[i] = max (ans[i + 1], ans[i + 2] + coins[i]);
	}
	return ans[0]; 
}

int main () {
	int t;
	cin >> t;
	for (int cas = 1; cas <= t; ++cas) {
		int n;
		cin >> n;
		int coins[n + 1];
		for (int i = 0; i < n; ++i) 
			cin >> coins[i];
		LL ans = solve (coins, n);
		cout << "Case " << cas << ": " << ans << '\n';
	}
	return 0;
} 