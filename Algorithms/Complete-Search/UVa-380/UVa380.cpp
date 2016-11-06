#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

struct Data {
	string source, time, duration, target;	
};

int n;
Data Calls[105];
set <string> M;

int conv (string s) {
	int ans = 0, r = 1;
	for (int i = 0; i < 4; ++i) 
		ans = s[i] - '0' + ans * 10;
	return ans;
}

bool comp (Data a, Data b) {
	return a.time < b.time;
}

string endLine (string t, string ext) {
	int s = M.size();
	M.insert (ext);
	if (s == M.size()) 
		return "9999";

	for (int i = 0; i < n && conv (Calls[i].time) <= conv (t); ++i) {
		int d = conv (Calls[i].time) + conv (Calls[i].duration);
		if (conv (Calls[i].time) <= conv (t) && d >= conv (t) && Calls[i].source == ext)
			return endLine (t, Calls[i].target);
	}
	return ext;
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (NULL);
	int t;
	cin >> t;
	cout << "CALL FORWARDING OUTPUT\n";
	for (int i = 1; i <= t; ++i) {
		n = -1;
		string s, t, d, ta;
		while (1) {
			cin >> s;
			if (s == "0000")
				break;
			cin >> t >> d >> ta;
			Calls[++n].source = s, Calls[n].time = t, Calls[n].duration = d, Calls[n].target = ta;
		}

		n += 1;
		sort (Calls, Calls + n, comp);
		
		cout << "SYSTEM " << i << "\n";
		string ext;
		while (1) {
			cin >> t;
			if (t == "9000")
				break;
			cin >> ext;
			string ans = endLine (t, ext);
			M.clear();
			cout << "AT " << t << " CALL TO " << ext << " RINGS " << ans << '\n'; 
		}
	}
	cout << "END OF OUTPUT\n";
	return 0;
}
