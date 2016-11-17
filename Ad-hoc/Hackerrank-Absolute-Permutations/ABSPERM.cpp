#include <iostream>
using namespace std;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        bool flag = false;
        int perm[n + 2] = {};
        
        for (int i = 1; i <= n; ++i) {
            if (i - k > 0) { 
                if (!perm[i - k]) {
                    perm[i - k] = i;
                    continue;
                }
            }
            
            if (k + i > n || perm[k + i]) {
                flag = true;
                break;
            }
            perm[k + i] = i;
        }
        
        if (flag) {
            cout << "-1\n";
            continue;   
        }
        
        for (int i = 1; i <= n; ++i)
            cout << perm[i] << ' ';
        cout << '\n';
    }
    return 0;
}
