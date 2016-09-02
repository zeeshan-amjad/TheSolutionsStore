#include <iostream>
#include <climits>
#include <cstring>
#include <cmath>

using namespace std;

int main () {
        int t, n, S;
        cin >> t;
        while (t--) {
                cin >> n >> S;
                int *coin = new int[n + 1];
                for (int i = 0; i < n; ++i) 
                        cin >> coin[i];
                int dp[n + 1][S + 1];
                for (int i = 0; i <= n; ++i)
                        for (int s = 0; s <= S; ++s) {
                                if (i == 0 || s == 0)
                                        dp[i][s] = 0;
                                else if (s - coin[i - 1] >= 0)
                                        dp[i][s] = max (coin[i - 1] + dp[i][s - coin[i - 1]], max (dp[i - 1][s], coin[i - 1] + dp[i - 1][s - coin[i - 1]]));
                                else
                                        dp[i][s] = dp[i - 1][s];
                        }
                cout << dp[n][S] << '\n';
        }
        return 0;
}
