#include <iostream>
using namespace std;

int main () {
	int t;
	cin >> t;
	while (t--) {
		long long ans = 0, n;
		string s1, s2, s3;
		cin >> s1 >> s2 >> s3 >> n;
		int l = s3.size();
		bool zero = false;
		for (int i = l - 1; i >= 0; i--) 
			if (s3[i] == '0')
				zero = true;
			else if (zero)
				ans++;
		l = s2.size();
		int a = 0;
		for (int i = l - 1; i >= 0; i--) 
			if (s2[i] == '0') 
				zero = true;
			else if (zero)
				ans++;
		if (zero) {
			int c = 0;
			for (int i = l - 1; i >= 0; i--)
				if (s2[i] == '1')
					c++;
			ans += c * (n - 1);
		}
		l = s1.size();
		for (int i = l - 1; i >= 0; i--)
			if (s1[i] == '0') 
				zero = true;
			else if (zero)
				ans++;
		ans += 1;
		cout << ans << '\n';
	}
	return 0;
}
