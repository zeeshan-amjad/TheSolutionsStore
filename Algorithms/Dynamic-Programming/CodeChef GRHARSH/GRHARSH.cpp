#include <iostream>
using namespace std;
 
int n, jar[2002];
 
int solve (int dp[][2002], int i, int j) {
    if (i > j)
        return 0;
    if (dp[i][j]) 
        return dp[i][j];
    return dp[i][j] = max ((((n - (j - i)) * jar[i]) + solve (dp, i + 1, j)), (((n - (j - i)) * jar[j]) + solve (dp, i, j - 1)));
}
 
int main() {
	int t;
	cin >> t;
	while (t--) {
	    cin >> n;
	    int dp[n + 1][2002] = {};
	    for (int i = 0; i < n; ++i)
	        cin >> jar[i];
	    cout << solve (dp, 0, n - 1) << '\n';
	}
	return 0;
}
