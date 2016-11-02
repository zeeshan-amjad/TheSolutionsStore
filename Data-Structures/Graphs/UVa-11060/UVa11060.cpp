#include <iostream>
#include <map>
#include <string>
#include <functional>
#include <queue>
using namespace std;

map <string, int> M;
map <int, string> S;
int n;

vector <int> Kahn (vector <int> *Graph, int *indegree) {
	vector <int> res;
	priority_queue <int, vector <int>, greater <int>> Q;
	for (int i = 1; i <= n; ++i) 
		if (!indegree[i])
			Q.push (i);
	
	bool visited[n + 2] = {0};
	while (!Q.empty()) {
		int v = Q.top(), s = Graph[v].size();
		Q.pop();
		res.push_back (v);
		//cout << v << '\n';
		visited[v] = true;
		for (int i = 0; i < s; ++i) 
			if (!visited[Graph[v][i]]) 
				if (!(--indegree[Graph[v][i]]))
					Q.push (Graph[v][i]);
	}
	return res;	
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (NULL);
	int k = 0;
	while (cin >> n) {
		k += 1;
		M.clear(), S.clear();
		vector <int> Graph[n + 2];
		int indegree[n + 2] = {};
		for (int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			M[s] = i + 1;
			S[i + 1] = s;
		}
		
		int m;
		cin >> m;
		for (int i = 0; i < m; ++i) {
			string a, b;
			cin >> a >> b;
			indegree[M[b]] += 1;
			Graph[M[a]].push_back (M[b]);
		}
	
		vector <int> res (Kahn (Graph, indegree));
		cout << "Case #" << k << ": Dilbert should drink beverages in this order: ";

		for (int i = 0; i < n; ++i) { 	
			cout << S[res[i]];
			if (i == n - 1) {
				cout << ".\n";
				continue;
			}
			cout << ' ';
		}
		cout << '\n';
	}
	return 0;
}
