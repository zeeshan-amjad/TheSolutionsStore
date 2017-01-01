#include <iostream>
#include <cstring>
#include <map>
     
using namespace std;
     
int n, a[100005];
map <int, int> M;
     
int main () {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
            
    for (int i = 1; i < n; ++i) { 
        int l = min (a[i], a[i - 1]), r = max (a[i], a[i - 1]);
        M[r] -= 1;
        M[l] += 1;
    }
    int m = 1, s = 0;
    map <int, int>::iterator it = M.begin();
    while (it != M.end()) {
        s += it->second;
        m = max (s, m);
        ++it;
    }
    cout << m;
    return 0;
} 
