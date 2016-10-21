#include <iostream>
using namespace std;

int n, m, a[101], b[101], dp[101][101], ans[101];

int main () {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= m; ++i)
		cin >> b[i];
	for (int i = 0; i <= n; ++i)                    //build dp table to find length of LCS
		for (int j = 0; j <= m; ++j) {
			if (!i || !j)
				dp[i][j] = 0;
			else if (a[i] == b[j])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else 
				dp[i][j] = max (dp[i - 1][j], dp[i][j - 1]);
		}

	int i = n, j = m, p = 0;
	while (p < dp[n][m]) {                         //use dp table to build the LCS
		if (dp[i][j] == dp[i - 1][j]) {
			i--;
			continue;
		}
		if (dp[i][j] == dp[i][j - 1]) {
			j--;
			continue;
		}
		if (dp[i][j] == 1 + dp[i - 1][j - 1]) {
                        ans[p++] = a[i];
                        i--, j--;
                        continue;
                }
	}
	
	while (p >= 1)
		cout << ans[--p] << ' ';
	return 0;
}
