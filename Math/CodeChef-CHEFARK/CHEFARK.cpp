#include <iostream>
#define MOD 1000000007
using namespace std;

long long fact[100005], comb[100005], n, k;

long long fast_pow (long long b, int e) {
    b = b % MOD;
    long long ans = 1;
    while (e > 0) {
        if (e & 1)
            ans = (ans * b) % MOD;
        e /= 2;
        b = (b * b) % MOD;
    }
    return ans % MOD;
}

void init() {
    fact[0] = 1;
    for (int i = 1; i <= 100000; ++i)
        fact[i] = (i * fact[i - 1]) % MOD;
}

void combination() {
    comb[0] = comb[n] = 1;
    for (int i = 1; i < n; ++i) 
        comb[i] = (fact[n] * fast_pow (fact[n - i] * fact[i], MOD - 2)) % MOD;
}

int sum (int l, int p = 1) {
    int ans = 0, lim = min (k, n);
    for (int i = l; i <= lim; i += p) 
        ans = (ans + comb[i]) % MOD;
    return ans;
}

int main() {
    ios_base::sync_with_stdio (0), cin.tie (0);
    init();
	int t, a[100005];
	cin >> t;
	while (t--) {
	    int z = 0, ans = 0;
	    cin >> n >> k;
	    for (int i = 0; i < n; ++i) {
	        cin >> a[i];
	        if (!a[i])
	            z += 1;
	    }
	    n -= z;
	    combination();
	    if (z) 
	        ans = sum (0);
	    else {
	        if (k & 1) 
	            ans = sum (1, 2);
	        else 
	            ans = sum (0, 2);
	    }
	    cout << ans << '\n';
	}
	return 0;
}
