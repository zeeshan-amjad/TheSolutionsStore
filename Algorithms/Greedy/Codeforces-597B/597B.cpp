#include <iostream>
#include <algorithm>
using namespace std;

int solve (pair <int, int> Order[], int n) {
	int current = 0, ans = 1;
	for (int i = 0; i < n; ++i) {
		if (Order[i].first <= Order[current].second) {
			if (Order[current].second > Order[i].second) 
				current = i;
			continue;
		}
		ans += 1;
		current = i;
	}
	return ans;
}

int main () {
	pair <int, int> Order[500005];
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) 
		cin >> Order[i].first >> Order[i].second;

	sort (Order, Order + n);
	int ans = solve (Order, n);
	cout << ans;
}
