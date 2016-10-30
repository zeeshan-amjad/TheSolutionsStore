#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, pair <string, string> > Edge;

vector <Edge> List;
map <string, string> Root;
map <string, int> Rank;
int m, n;

string findSet (string s) {
	if (Root[s] != s)
		return s = findSet (Root[s]);
	return Root[s];
}

void unionSet (string a, string b) {
	string Ra = findSet (a), Rb = findSet (b);
	if (Ra == Rb)
		return;
	if (Rank[Ra] < Rank[Rb]) {
		Root[Ra] = Rb;
		return;
	}
	Root[Rb] = Ra;
	if (Rank[Ra] == Rank[Rb])
		Rank[Ra]++;
}

int Kruskal_MST () {
	for (int i = 0; i < n; ++i) {
		Root[List[i].second.first] = List[i].second.first;
		Root[List[i].second.second] = List[i].second.second;
		Rank[List[i].second.first] = Rank[List[i].second.second] = 0;
	}
	
	sort (List.begin(), List.end());
	int weight = 0;
	for (int i = 0; i < n; ++i) {
		if (findSet (List[i].second.first) == findSet (List[i].second.second))
			continue;
		unionSet (List[i].second.first, List[i].second.second);
		weight += List[i].first;
	}
	
	return weight;
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (NULL);
	int t;
	cin >> t;
	while (t--) {
		List.clear();
		Root.clear();
		Rank.clear();		
		cin >> m >> n;
		for (int i = 0; i < n; ++i) {
			string u, v;
			int w;
			cin >> u >> v >> w;
			Edge E = {w, {u, v}};
			List.push_back (E);
		}
	 	int ans = Kruskal_MST();		
		cout << ans << '\n';
		if (t)
			cout << '\n';
	}
	return 0;
}
