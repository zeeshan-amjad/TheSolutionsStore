#include <iostream>
#include <cstdio>
using namespace std;

int root[100001], Rank[100001], p[100001], visited[100001] = {0};
long long ans = 0, sum[100001], a[100001];

void makeSet (int x) {
    root[x] = x;
    Rank[x] = 0;
    sum[x] = a[x];
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
    if (Rank[Rx] > Rank[Ry]) {
        root[Ry] = Rx;
	sum[Rx] += sum[Ry]; 
    }
    else {
        root[Rx] = Ry;
	sum[Ry] += sum[Rx];
        if (Rank[Rx] == Rank[Ry])
            Rank[Ry]++;
    }
}

int main () {
    int n;
    long long op[100001];
    cin >> n;
    for (int i = 1; i <= n; ++i)
	cin >> a[i];
    for (int i = 0; i < n; ++i)
	cin >> p[i];
    for (int i = n - 1; i >= 0; i--) {
	op[i] = ans;
	makeSet (p[i]);
	visited[p[i]] = 1;
	if (p[i] - 1 && visited[p[i] - 1]) 
		unionSet (p[i] - 1, p[i]);
	if (p[i] + 1 <= n && visited[p[i] + 1]) 
		unionSet (p[i], p[i] + 1);
    	ans = max (ans, sum[findSet (p[i])]);
    }
    for (int i = 0; i < n; ++i)
	cout << op[i] << '\n';
    return 0;
}
