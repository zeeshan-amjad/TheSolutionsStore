#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string ans, s;
    int n, k, x;
    cin >> n >> k;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (!i) {
            ans += s[i];
            continue;
        }
        if (i < k)
            ans += ((s[i - 1] - 48) ^ (s[i] - 48)) + 48;
        else
            ans += ((s[i - 1] - 48) ^ (ans[i - k] - 48) ^ (s[i] - 48)) + 48;
    }
    cout << ans;
    return 0;
}
