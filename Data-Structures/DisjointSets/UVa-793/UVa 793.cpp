#include <iostream>
#include <cstdio>
using namespace std;

int root[1001], Rank[1001];

void makeSet (int x) {
    root[x] = x;
    Rank[x] = 0;
}

int findSet (int x) {
    if (root[x] != x)
        root[x] = findSet (root[x]);
    return root[x];
}

void unionSet (int x, int y) {
    int Rx = findSet(x), Ry = findSet(y);
    if (Rx == Ry)
        return;
    if (Rank[Rx] > Rank[Ry])
        root[Ry] = Rx;
    else {
        root[Rx] = Ry;
        if (Rank[Rx] == Rank[Ry])
            Rank[Ry]++;
    }
}

int main () {
    int t;
    scanf ("%d", &t);
    while (t--) {
        int n, succ = 0, unsucc = 0;
        scanf ("\n%d\n", &n);
        for (int i = 1; i <= n; ++i)
            makeSet (i);
        while (1) {
            char c;
            int l, r;
            string s;
           if (!getline (cin, s) || s.empty())
                break;
            sscanf (s.c_str(), "%c %d %d", &c, &l, &r);
            if (c == 'c')
                unionSet (l, r);
            else
                findSet (l) == findSet(r) ? succ++ : unsucc++;
        }
        printf ("%d,%d\n", succ, unsucc);
        if (t)
            printf ("\n");
    }
    return 0;
}
