#include <iostream>
using namespace std;

#define MOD 1000000007

string a, b;
char s[100005];
long long ans = 0;
int l;

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

int calculate (int pos1, int pos2) {
        if (pos2 - pos1 == 1)
                return 0;
        if (pos2 - pos1 == 2)
                return -1;
        if (pos2 - pos1 == 3) {
                if (s[pos1 + 1] != s[pos2 - 1])
                        return -1;
                if (s[pos1 + 1] == '4')
                        return 2;
                if (s[pos1 + 1] == '3')
                        return 1;
        }
        if (s[pos1 + 1] == '4' || s[pos2 - 1] == '4')
                return -1;
        int count = 0, current = -1;
        for (int i = pos1 + 1; i < pos2; ++i)
                if (s[i] == '4') {
                        count++;
                        if (((i - pos1) & 1) && current == -1)
                                return -1;
                        if (current != -1 && (!((i - current) & 1) || (i - current == 1)))
                                return -1;
                        current = i;
                }
        if (!count && !((pos2 - pos1) & 1))
                return -1;
        if (count && ((pos2 - current) & 1))
                return -1;
        return count + 1;
}

int solve() {
	if (l == 1) 
		return 1;
	if (l >= 2 && s[l - 2] != '2')
		return -1;
	if (l == 2) 
		return 2;
	if (l == 3) {
		if (s[0] != '2')
			return -1;
		return 3;
	}
	int pos1 = -1, pos2 = 0, v = 1;
	while (pos2 < l - 2) {
		for (pos2 = pos1 + 1; s[pos2] != '2'; ++pos2);
		int res = calculate (pos1, pos2);
		if (res == -1)
			return -1;
		v += 1 + res;
		pos1 = pos2;
	}	
	return v;
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (NULL);
	int t;
	cin >> t;
	while (t--) {
		ans = 0;
		cin >> a >> b;
		l = a.size();
		for (int i = 0; i < l; ++i)
			s[i] = ((a[i] - '0') + (b[i] - '0') + '0');
		int r = solve();
		if (r == -1)
			ans = 0;
		else 
 			ans = fast_pow (2, r);
		cout << ans << '\n';
	}
	return 0;
}
