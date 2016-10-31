#include <iostream>
using namespace std;

int main () {
        string s;
        cin >> s;
        int ans = 0, p = -1, l = s.size();
        for (int i = 0; i < l; ++i) 
                if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y') {
                        ans = max (ans, i - p);
                        p = i;
                }
                
        ans = max (ans, l - p);
        cout << ans;
        return 0;
}
