#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

int main() {
    stack <int> st;
    char s[1009];
    int t, len, i, flag;
    cin >> t;
    while (t--) {
        flag = 0;
        scanf ("%s", s);
        len = strlen (s);
        for (i = 0; i < len; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else if (s[i] == ')')
                if(!st.empty() && st.top() == '(') 
                    st.pop();
                else {
                    flag = 1;
                    break;
                }
            else if (s[i] == '}')
                if(!st.empty() && st.top() == '{') 
                    st.pop();
                else {
                    flag = 1;
                    break;
                }
            else if (s[i] == ']') 
                if(!st.empty() && st.top() == '[') 
                    st.pop();
                else {
                    flag = 1;
                    break;
                }
        }
        if (flag || !st.empty())
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
        while (!st.empty ())
            st.pop();
    }
    return 0;
}
