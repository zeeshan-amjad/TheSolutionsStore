#include <iostream>
#define LL long long

using namespace std;

int main() {
	LL n;
	cin >> n;
	if (n == 1 || n == 2)
	    cout << -1;
	else {
	    LL a, b;
	    if (n & 1)
	        a = (n * n + 1) / 2, b = (n * n - 1) / 2;
	    else
	        a = (n * n + 4) / 4, b = (n * n - 4) / 4;
	    cout << a << ' ' << b;
	}
	return 0;
}
