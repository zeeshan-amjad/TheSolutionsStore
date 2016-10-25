#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int M[101][101], n, ans = INT_MIN;

int kadane (vector <int> v) {
	int s = 0, m = INT_MIN;
	for (int i = 0; i < n; ++i) {
		s = max (0, s + v[i]);
		m = max (m, s);
	}	
	if (!m) {
		m = INT_MIN;
		for (int i = 0; i < n; ++i) 
			m = max (m, v[i]);
	}
	return m;
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (NULL);
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> M[i][j];
	for (int l = 0; l < n; ++l) {
		vector <int> v (n, 0);
		for (int r = l; r < n; ++r) {
			for (int i = 0; i < n; ++i)
				v[i] += M[i][r];
			ans = max (ans, kadane (v));
		}
	}
	cout << ans << '\n';
	return 0;
}
