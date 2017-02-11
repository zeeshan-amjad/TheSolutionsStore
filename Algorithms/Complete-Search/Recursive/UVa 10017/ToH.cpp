#include <iostream>
#include <vector>
using namespace std;

int i = 1;

void Print (vector <int> *v) {
	for (int j = 1; j <= 3; ++j) {
		cout << (char)(64 + j) << "=>";
		for (int i = 0; i < v[j].size(); ++i) {
			cout << " ";
			if (!i)
				cout << "  ";
			cout << v[j][i];
		}
		cout << "\n";
	}
	cout << '\n';
}

void ToH (vector <int> *v, int from, int to, int extra, int n, int m) {
	if (n == 1 && i <= m) {
		int a = v[from].back();
		v[to].push_back (a);
		v[from].pop_back ();
		i += 1;
		Print (v);
		return;
	}

	if (i <= m) ToH (v, from, extra, to, n - 1, m);
	if (i <= m) ToH (v, from, to, extra, 1, m);
	if (i <= m) ToH (v, extra, to, from, n - 1, m);
}

int main () {
	int n, m, c = 1;
	while (cin >> n >> m, n || m) {
		cout << "Problem #" << c++ << "\n\n";
		vector <int> v[4];
		for (int j = n; j > 0; j--)
			v[1].push_back(j);
		
		Print (v);
		ToH (v, 1, 3, 2, n, m);
		i = 1;
	}
	return 0;
}