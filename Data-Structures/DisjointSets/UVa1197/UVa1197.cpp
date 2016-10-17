#include <iostream>
using namespace std;

int root[30005], Rank[30005];

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
	ios_base::sync_with_stdio (false), cin.tie (NULL);
	int n, m;
	while (cin >> n >> m, n || m) {
		for (int i = 0; i < n; ++i)
			makeSet (i);
		for (int i = 0; i < m; ++i) {
			int l, a, b;
			cin >> l;
			for (int j = 0; j < l; ++j) {
				if (!j)	{
					cin >> a;	
					continue;
				}
				cin >> b;
				unionSet (a, b);
				a = b;
			}
		}
		int p = findSet (0), c = 0;
		for (int i = 0; i < n; ++i)
			if (p == findSet (i))
				c++;
		cout << c << '\n';
	}
	return 0;
}
