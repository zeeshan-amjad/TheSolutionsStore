#include <iostream>
using namespace std;

int main() {
    int l, r, lz;
    cin >> l >> r;
    lz = __builtin_clz (l ^ r);	//count leading zeros in 32-bit representation
    cout << (1 << (32 - lz)) - 1; //equivalent to ---> pow (2, 32 - lz) - 1
    return 0;
}
