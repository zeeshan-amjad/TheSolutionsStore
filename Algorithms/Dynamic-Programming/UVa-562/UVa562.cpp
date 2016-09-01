#include <iostream>
#include <climits>
#include <cstring>
#include <cmath>

using namespace std;

int main () {
        int t, n;
        cin >> t;
        while (t--) {
                cin >> n;
                int *coin = new int[n + 1], S = 0;
                for (int i = 0; i < n; ++i) {
                        cin >> coin[i];
                        S += coin[i];
                }
                int sum = S / 2, dp[n + 1][sum + 1];
                for (int i = 0; i <= n; ++i)
                        for (int s = 0; s <= sum; ++s) {
                                if (i == 0 || s == 0)
                                        dp[i][s] = 0;
                                else if (s - coin[i - 1] >= 0)
                                        dp[i][s] = max (dp[i - 1][s], coin[i - 1] + dp[i - 1][s - coin[i - 1]]);
                                else
                                        dp[i][s] = dp[i - 1][s];
                        }
                int ans = S - 2 * dp[n][sum];
                cout << ans << '\n';
        }
        return 0;
}
