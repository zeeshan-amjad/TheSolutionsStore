#include <iostream>
using namespace std;

int main () {
	ios_base::sync_with_stdio (false), cin.tie (NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, m, coin[22];
		bool ans = false;
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			cin >> coin[i];
		
		int l = (1 << n);
		for (int i = 0; i < l; ++i) {
			int s = 0;

			for (int j = 0; j < n; ++j) 
				if ((1 << j) & i)
					s += coin[n - 1 - j];
			
			if (s == m) {
				ans = true;
				break;
			}
		}

		if (ans)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}
