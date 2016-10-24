#include <iostream>
using namespace std;

int l1, l2, dp[1000][1000];
string a, b;

int editDistance (string a, string b, int l1, int l2) {
	//int l1 = a.size(), l2 = b.size();
	for (int i = 0; i <= l1; ++i)
        	for (int j = 0; j <= l2; ++j) {
                	if (!i || !j) {
				dp[i][j] = i + j;
				continue;
			}
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
				continue;
			}
                        dp[i][j] = min (min (dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                }
	return dp[l1][l2];
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (NULL);
	while (cin >> l1 >> a >> l2 >> b) 
		cout << editDistance (a, b, l1, l2) << '\n';
	return 0;
}
