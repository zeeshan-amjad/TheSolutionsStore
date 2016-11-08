#include <iostream>
#include <string>
#include <vector>
using namespace std;

string rule, word[103];
vector <int> v;
int n, words;

void solve (int p) {
	if (p == n) {
		for (int i = 0; i < n; ++i) 
			if (rule[i] == '0')
				cout << v[i];
			else
				cout << word[v[i]];
		cout << '\n'; 
		return;
	}

	int l;
	if (rule[p] == '0') 
		l = 10;
	else 
		l = words;

	for (int i = 0; i < l; ++i) {
		v.push_back (i);
		solve (p + 1);
		v.pop_back ();
	}
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (NULL);
	while (cin >> words) { 
		cout << "--\n";
		for (int i = 0; i < words; ++i)
			cin >> word[i];
		int r;
		cin >> r;
		while (r--) {
			cin >> rule;
			n = rule.size();
			solve (0);
		}
	}
	return 0;
}
