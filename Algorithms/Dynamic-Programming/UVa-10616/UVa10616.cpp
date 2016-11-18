#include <iostream>
#include <cstring>
using namespace std;

#define LL long long

int N, M, D, Q;
LL dp[202][202][12], a[202];

LL solve (int i, LL sum, int n) {
	if (n == M)
		return sum == 0;
	
	if (i == N)
		return 0;

	if (dp[i][sum][n])
		return dp[i][sum][n];
	
	return dp[i][sum][n] = solve (i + 1, (sum + a[i]) % D, n + 1) + solve (i + 1, sum % D, n);
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (NULL);
	int set = 1;
	while (1) {
		cin >> N >> Q;
		
		if (!N && !Q)
			break;

		for (int i = 0; i < N; ++i)
			cin >> a[i];
		
		cout << "SET " << set << ":\n";

		for (int i = 0; i < Q; ++i) {
			cin >> D >> M;
			memset (dp, 0, sizeof (dp));
			LL ans = solve (0, 0, 0);
			cout << "QUERY " << i + 1 << ": " << ans << "\n";
		}

		set += 1;
	}
	return 0;
}
