#include <bits/stdc++.h>
using namespace std;

int main () {
	ios_base::sync_with_stdio (false), cin.tie (NULL);
	int t;
	cin >> t;
	for (int cas = 1; cas <= t; ++cas) {
		string a, b;
		vector <int> v;
		cin >> a >> b;
		int first = 0, second = 0;
		for (int i = 0; i < a.size(); ++i) {
			if (a[i] == '?' and b[i] == '?') {
				v.push_back (i);
				if (first)
					a[i] = '0', b[i] = '9';
				else if (second)
					a[i] = '9', b[i] = '0';
				else 
					a[i] = b[i] = '0';
			}
			else if (a[i] == '?') {
				if (first)
					a[i] = '0';
				else if (second)
					a[i] = '9';
				else 
					a[i] = b[i];
			}
			else if (b[i] == '?') {
				if (first)
					b[i] = '9';
				else if (second)
					b[i] = '0';
				else 
					b[i] = a[i];
			}
			else if (!first and !second) {
				if (a[i] > b[i]) {
					first = 1;
					for (int j = 0; j < v.size(); ++j) 
						b[v[j]] = '1';
				}
				else if (b[i] > a[i]) {
					second = 1;
					for (int j = 0; j < v.size(); ++j) 
						a[v[j]] = '1';
				}
			}
		}
		cout << "Case #" << cas << ": " << a << ' ' << b << '\n';
	}
	return 0;
}