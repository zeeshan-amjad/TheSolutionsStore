#include <iostream>
#include <bitset>
#define BOOSTIO ios_base::sync_with_stdio (0), cin.tie (0)

using namespace std;

int main () {
        BOOSTIO;
        int c = 0, n;
        while (cin >> n, n) {
                c += 1;
                bitset <10000> year;
                year.set();
                for (int i = 0; i < n; ++i) {
                        int y, a, b;
                        cin >> y >> a >> b;
                        for (int i = 0; i < y; ++i)
                                year[i] = 0;
                        for (int i = y; i < 10000; ++i)
                                if (i != y && (i - y) % (b - a))
                                        year[i] = 0;
                }
                cout << "Case #" << c << ':' << '\n';
                bool flag = false;
                for (int i = 0; i < 10000; ++i)
                        if (year[i]) {
                                flag = true;
                                cout << "The actual year is " << i << ".\n\n";
                                break;
                        }
                if (!flag)
                        cout << "Unknown bugs detected.\n\n";
        }
        return 0;
}
