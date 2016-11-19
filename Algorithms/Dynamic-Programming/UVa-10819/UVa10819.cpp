#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

int m, n, dp[102][10300], price[102], favour[102];

int solve (int i, int p) {
	if (p > m && m <= 1800)
		return INT_MIN;
	if (p > m + 200)
		return INT_MIN;
	if (i == n) {
		if (p > m && p <= 2000)
			return INT_MIN;
		return 0;
	}

	if (dp[i][p])
		return dp[i][p];

	return dp[i][p] = max (solve (i + 1, p), favour[i] + solve (i + 1, p + price[i]));
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (NULL);
	while (cin >> m >> n) {
		memset (dp, 0, sizeof (dp));
		for (int i = 0; i < n; ++i)
			cin >> price[i] >> favour[i];
		cout << solve (0, 0) << '\n';
	}
	return 0;
}
