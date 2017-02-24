#include <bits/stdc++.h>
using namespace std;

vector <int> prime;     

void buildPrime (int s) {       
    prime.push_back (2);
    int i = 3;
    bool flag;
    while (prime[prime.size() - 1] <= s) {
        flag = true;
        int j = 0;
        while (prime[j] * prime[j] <= i) {
            if (!(i % prime[j])) {
                flag = false;
                break;
            }
            j += 1;
        }    
        if (flag)
            prime.push_back (i);
        i += 2;
    }
}

int main() {
    int n;
    cin >> n;
    vector <int> a (n + 4, 1);
	buildPrime (n + 3);
	for (int i = 0; prime[i] <= n + 2; ++i)
	    for (int j = prime[i] + prime[i]; j <= n + 2; j += prime[i]) 
	        if (a[j] == a[prime[i]])
	            a[j] += 1;
	set <int> s;
	for (int i = 2; i <= n + 1; ++i)
	    s.insert (a[i]);
	cout << s.size() << '\n';
	for (int i = 2; i <= n + 1; ++i)
	    cout << a[i] << ' ';
	return 0;
}
