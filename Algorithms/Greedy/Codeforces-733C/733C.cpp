#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, k, z, a;
string d;
vector <int> orig, p, b;

bool set (int pos, vector <int> &v, bool state) {
        int l = v.size();
        for (int i = pos; i < l - 1; ++i) {
                if (v[i] != v[i + 1] && v[i] + v[i + 1] > b[pos])
                    return false;
                
                if (v[i] > v[i + 1]) {
                        v[i] += v[i + 1];
                        if (!state) {
                            p.push_back (i + 1);
                            d += 'R';
                        }
                        else {
                            p.push_back (v.size() + 1 - (i + 1));
                            d += 'L';
                        }
                        v.erase (v.begin() + i + 1);
                        l--;
                        i = pos - 1;
                }

                else if (v[i] < v[i + 1]) {
                        v[i + 1] += v[i];
                        
                        if (!state) {
                            p.push_back (i + 2);
                            d += 'L';
                        }
                        else {
                            p.push_back (v.size() + 1 - (i + 2));
                            d += 'R';
                        }
                        v.erase (v.begin() + i);
                        l--;
                        i = pos - 1;
                }
                
                if (v[pos] == b[pos]) 
                        return true;
                
                if (v[pos] > b[pos])
                        return false;
                
        }
        
        return false;
}

bool solve (vector <int> &v, bool state = false) {
    for (int i = 0; i < k; ++i) {
        if (v[i] == b[i])
            continue;
        if (!set (i, v, state) || p.size() > n - k) 
            return false;
    }
    if (p.size() != n - k) 
        return false;
    return true;
}

int main () {
        cin >> n;
        for (int i = 0; i < n; ++i) {
                cin >> a;
                orig.push_back (a);
        }
        
        cin >> k;
        for (int i = 0; i < k; ++i) {
                cin >> a;
                b.push_back (a);
        }
        
        vector <int> v (orig);
        if (n == 1) {
            if (v[0] == b[0]) 
                cout << "YES\n";
            else
                cout << "NO\n";
            return 0;    
        }
        
        if (!solve (v)) {
            reverse (orig.begin(), orig.end());
            reverse (b.begin(), b.end());
            p.clear();
            d.clear();
            vector <int> v1 (orig);
            if (!solve (v1, true)) {
                cout << "NO\n";
                return 0;
            }
        }
        
        cout << "YES\n";
        z = p.size();
        for (int i = 0; i < z; ++i) 
            cout << p[i] << ' ' << d[i] << '\n';
            
        return 0;
}
