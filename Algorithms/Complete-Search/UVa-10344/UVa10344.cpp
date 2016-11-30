#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

LL a[7] = {0LL};
char c[] = {'+', '-', '*'};

LL eval (LL a, LL b, char c) {
	if (c == '+')
		return a + b;
	if (c == '-')
		return a - b;
	return a * b;
}

bool solve (LL a, LL b, int i) {
	if (i == 5) {
		if (a == 23)
			return true;
		return false;
	}

	for (int j = 0; j < 3; ++j) {
		LL s = eval (a, b, c[j]);
		if (solve (s, ::a[i + 1], i + 1))
			return true;
	}
	
	return false;
}

int main () {
	while (cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4], a[0] + a[1] + a[2] + a[3] + a[4]) {
		bool flag = false;
		sort (a, a + 5);
		do {
			if (solve (a[0], a[1], 1)) {
				cout << "Possible\n";
				flag = true;
				break;
			}
		} while (next_permutation (a, a + 5));
		if (!flag)
			cout << "Impossible\n";
	}
	return 0;
}
