#include <iostream>
using namespace std;

int main () {
    int n, check[2] = {0};
    string s;
    cin >> n >> s;

    for (int i = 0; i < n; ++i)
        if ((i & 1) && s[i] != 'b')
            check[1]++;
        else if (!(i & 1) && s[i] != 'r')
            check[0]++;

    int ans = max (check[0], check[1]);

    check[0] = check[1] = 0;
    for (int i = 0; i < n; ++i)
        if ((i & 1) && s[i] != 'r')
            check[0]++;
        else if (!(i & 1) && s[i] != 'b')
            check[1]++;

    ans = min (ans, max (check[0], check[1]));
    cout << ans;
    return 0;
}
