#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, n, p, q;

int main () {
	ios_base::sync_with_stdio (false), cin.tie (NULL);
	cin >> t;
	for (int k = 1; k <= t; ++k) {
		vector <int> lcs;
		cin >> n >> p >> q;
		int pos[n * n + 1] = {};
		for (int i = 1; i <= p + 1; ++i) {
			int v;
			cin >> v;
			pos[v] = i;
		}
		for (int i = 1; i <= q + 1; ++i) {
			int v;
			cin >> v;	
			if (!pos[v])
				continue;
			if (!lcs.size() || pos[v] > lcs.back()) 
				lcs.push_back (pos[v]);
			else
				*lower_bound (lcs.begin(), lcs.end(), pos[v]) = pos[v];
		}
		int ans = lcs.size();
		cout << "Case " << k << ": " << ans << '\n';
	}
	return 0;
}
