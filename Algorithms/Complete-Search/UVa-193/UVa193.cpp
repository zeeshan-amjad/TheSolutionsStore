#include <iostream>
#include <bitset>
#include <vector>
#define MAX 101
using namespace std;

int n, k;
vector <int> ans;
vector <vector <int> > list;
bitset <MAX> painted, color;

void solve (int i) {
        if (i == n + 1) {
                int count = 0;
                for (int j = 1; j <= n; ++j)
                        if (color[j])
                                count += 1;
                if (count > ans.size()) {
                        ans.clear();
                        for (int j = 1; j <= n; ++j)
                                if (color[j])
                                        ans.push_back (j);
                }
                return;
        }

        bool black = true;
        for (vector <int>::iterator it = list[i].begin(); it != list[i].end(); ++it)
                if (painted[*it] && color[*it]) {
                        black = false;
                        break;
                }

        painted.set (i);

        if (black) {
                color.set (i);
                solve (i + 1);
        }

        color.reset (i);
        solve (i + 1);
}

int main () {
        int t;
        cin >> t;
        while (t--) {
                ans.clear();
                painted.reset();
                color.set();

                cin >> n >> k;
                list.assign (n + 1, vector <int> ());
                while (k--) {
                        int l, r;
                        cin >> l >> r;
                        list[l].push_back (r), list[r].push_back (l);
                }

                solve (1);
                cout << ans.size() << '\n';
                for (vector <int>::iterator it = ans.begin(); it != ans.end() - 1; ++it)
                        cout << *it << ' ';
                if (ans.size() > 0)
                        cout << *(ans.end() - 1) << '\n';
        }
        return 0;
}
