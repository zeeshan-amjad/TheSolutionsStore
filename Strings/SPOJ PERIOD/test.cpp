#include <iostream>
#include <cstring>
#define MAX 1000001
#define MOD 1000000007
using namespace std;

int F[MAX], n;
string s;

void build_failure_function (string pattern) {
    memset (F, 0, sizeof (F));
    F[0] = F[1] = 0;
    for (int i = 2; i <= pattern.size(); ++i) {
        int j = F[i - 1];
        while (1) {
            if (pattern[i - 1] == pattern[j]) {
                F[i] = j + 1;
                break;
            }            
            if (!j) {
                F[i] = 0;
                break;
            }
            j = F[j];
        }
    }
}

int calc (int i) {
    int l = i;
    while (i >= l / 2) {
	if (!(l % (l - F[i])))
	    break;
        i = F[i];
    }
    return l / (l - F[i]);
}

int main () {
    ios_base::sync_with_stdio (false), cin.tie (NULL);
    int t;
    cin >> t;
    for (int j = 1; j <= t; ++j) {
  	cout << "Test case #" << j << '\n'; 
        cin >> n >> s;
	build_failure_function (s);
	for (int i = 2; i <= n; ++i) {
	    int c = calc (i);
            if (c > 1)
		cout << i << ' ' << c << '\n';
	}
	cout << '\n';
    }
    return 0;
}
