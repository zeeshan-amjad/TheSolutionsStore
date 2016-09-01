#include <iostream>

using namespace std;

int main () {
    int s, a = 0;
    while (cin >> s, s) {
        if (a)
            cout << '\n';
        a = 1;
        int *lotto = new int[s];
        for (int i = 0; i < s; ++i)
            cin >> lotto[i];
        for (int i = 0; i < s - 5; ++i)
            for (int j = i + 1; j < s - 4; ++j)
                for (int k = j + 1; k < s - 3; ++k)
                    for (int l = k + 1; l < s - 2; ++l)
                        for (int m = l + 1; m < s - 1; ++m)
                            for (int n = m + 1; n < s; ++n)
                                cout << lotto[i] << ' ' << lotto[j] << ' ' << lotto[k] << ' ' << lotto[l] << ' ' << lotto[m] << ' ' << lotto[n] << '\n';
    }
    return 0;
}
