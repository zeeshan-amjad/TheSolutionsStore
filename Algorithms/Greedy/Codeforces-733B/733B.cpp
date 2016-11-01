#include <iostream>
using namespace std;

int main () {
    int n, neg = 0, pos = 0, mp = 0, mn = 0, ppos = 0, pneg = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        if (b - a < 0) {
            neg += a - b;
            if (a - b > mn) {  
                pneg = i + 1;
                mn = a - b;
            }
        }
        else {
            pos += b - a;
            if (b - a > mp) {
                ppos = i + 1;
                mp = b - a;
            }
        }
    }
    int ans;
    if (neg + mp > pos + mn)
        ans = ppos;
    else
        ans = pneg;
    cout << ans;
    return 0;
}
