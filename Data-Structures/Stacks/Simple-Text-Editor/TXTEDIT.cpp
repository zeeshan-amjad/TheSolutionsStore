#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;

int main() {
    stack <char> current, bin;
    stack < pair<int, int> > op;
    int i = 0, n, q, j, k, c, count = 0, diff, len;
    char s[1000005];
    cin >> n;
    while (i < n) {
        cin >> q;
        if (q == 1) {
            scanf ("%s", s);
            len = strlen (s);
            for (j = 0; j < len; j++)
                current.push (s[j]);
            op.push (make_pair (1, len));
            count += len;
        }
        else if (q == 2) {
            cin >> k;
            for (j = 1; j <= k; j++) {
                c = current.top();
                current.pop();
                bin.push (c);
            }
            op.push (make_pair (2, k));
            count -= k;
        }
        else if (q == 3) {
            cin >> k;
            diff = count - k;
            for (j = 1; j <= diff; j++) {
                c = current.top();
                current.pop();
                bin.push (c);
            }
            cout << current.top() << '\n';
            for (j = 1; j <= diff; j++) {
                c = bin.top();
                bin.pop();
                current.push (c);
            }
        }
        else {
            pair <int, int> p;
            p = op.top ();
            op.pop();
            if (p.first == 1) {
                for (j = 1; j <= p.second; j++)
                    current.pop();
                count -= p.second;
            }
            else {
                for (j = 1; j <= p.second; j++) { 
                    current.push (bin.top());
                    bin.pop();
                }
                count += p.second;
            }
        }
        i++;
    }
    return 0;
}
