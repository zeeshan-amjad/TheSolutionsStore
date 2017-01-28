#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

vector <pair <LL, LL>> F;

int main() {
	LL n, k;
	cin >> n >> k;
	LL s = sqrt (n);
	for (int i = 1; i <= s; ++i)
	    if (!(n % i)) 
	        F.push_back ({i, n / i});
	
	if (k > 2 * F.size()) {
	    cout << -1;
	    return 0;
	}
	
	if (k <= F.size()) {
	    cout << F[k - 1].first;
	    return 0;
	}
	
	if (F[F.size() - 1].first == F[F.size() - 1].second) {
	    if (!(F.size() - (k - F.size()))) {
	        cout << -1;
	        return 0;
	    }
	    cout << F[F.size() - (k - F.size()) - 1].second;
	    return 0;
	}
	
	cout << F[F.size() - (k - F.size())].second;
	return 0;
}
