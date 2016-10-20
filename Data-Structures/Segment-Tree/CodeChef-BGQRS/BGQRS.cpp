#include <iostream>
using namespace std;
 
typedef long long LL;
typedef pair <LL, LL> Node;
 
#define twos first
#define fives second
 
Node get5sand2s (LL n) {
	Node temp;
	while (!(n % 2)) {
		temp.twos++;
		n /= 2;
	}
	while (!(n % 3))
		n /= 3;
	while (!(n % 5)) {
		temp.fives++;
		n /= 5;
	}
	return temp;
}
 
Node multiply (Node n1, Node n2) {
	Node temp;	
	temp.twos = n1.twos + n2.twos;
	temp.fives = n1.fives + n2.fives;
	return temp;
}
 
Node sieve[100005], a[100005], csieve[100005], zero, st[300005];
pair <Node, Node> RLazy[300005], MLazy[300005];
 
Node fast_pow (Node b, LL e) {
        Node t;
        t.twos = e * b.twos;
        t.fives = e * b.fives;
        return t;
}
 
void construct (int i, int s, int e) {
	if (e < s)
		return;	
	if (s == e) {
		st[i] = a[s];
		return;
	}
	int mid = (s + e) / 2;
	construct (i * 2 + 1, s, mid);
	construct (i * 2 + 2, mid + 1, e);
	st[i] = multiply (st[i * 2 + 1], st[i * 2 + 2]);
}
 
void update (int i, int s, int e, int l, int r, Node v, bool type) {
	if (RLazy[i].first.twos || RLazy[i].first.fives || RLazy[i].second.first) {
                Node t;
                t.twos = csieve[RLazy[i].second.second].twos - csieve[RLazy[i].second.first - 1].twos;
                t.fives = csieve[RLazy[i].second.second].fives - csieve[RLazy[i].second.first - 1].fives;
                st[i] = multiply (t, fast_pow (RLazy[i].first, e - s + 1));
 
                if (s != e) {
                        MLazy[i * 2 + 1].first = MLazy[i * 2 + 2].first = zero;
                        RLazy[i * 2 + 1].first = RLazy[i * 2 + 2].first = RLazy[i].first;
                        RLazy[i * 2 + 1].second.first = RLazy[i].second.first;
                        RLazy[i * 2 + 2].second.second = RLazy[i].second.second;
                        int mid = (RLazy[i].second.first + RLazy[i].second.second) / 2;
                        RLazy[i * 2 + 1].second.second = mid;
                        RLazy[i * 2 + 2].second.first = mid + 1;
                }
                RLazy[i].first = zero;
		RLazy[i].second.first = 0;
        }
 
        if (MLazy[i].first.twos || MLazy[i].first.fives) {
                st[i] = multiply (st[i], fast_pow (MLazy[i].first, e - s + 1));
                if (s != e) {
                        MLazy[i * 2 + 1].first = multiply (MLazy[i * 2 + 1].first, MLazy[i].first);
                        MLazy[i * 2 + 2].first = multiply (MLazy[i * 2 + 2].first, MLazy[i].first);
                }
                MLazy[i].first = zero;
        }
	
	if (e < s || e < l || s > r)
		return;
 
        if (s >= l && e <= r) {
                if (type) {
                        st[i] = multiply (st[i], fast_pow (v, e - s + 1));
                        if (s != e) {
                                MLazy[i * 2 + 1].first = multiply (MLazy[i * 2 + 1].first, v);
                                MLazy[i * 2 + 2].first = multiply (MLazy[i * 2 + 2].first, v);
                        }
                        return;
                }
                else {
                        Node t;
                        t.twos = csieve[e - l + 1].twos - csieve[s - l].twos;
                        t.fives = csieve[e - l + 1].fives - csieve[s - l].fives;
                        st[i] = multiply (t, fast_pow (v, e - s + 1));
                        if (s != e) {
                                MLazy[i * 2 + 1].first = MLazy[i * 2 + 2].first = zero;
                                RLazy[i * 2 + 1].first = RLazy[i * 2 + 2].first = v;
				int m = (s + e) / 2 - l + 1;
				RLazy[i * 2 + 1].second.first = s - l + 1;
                                RLazy[i * 2 + 1].second.second = m;
                                RLazy[i * 2 + 2].second.first = m + 1;
                                RLazy[i * 2 + 2].second.second = e - l + 1;
                        }
                        return;
                }
        }
 
        int mid = (s + e) / 2;
        update (i * 2 + 1, s, mid, l, r, v, type);
        update (i * 2 + 2, mid + 1, e, l, r, v, type);
        st[i] = multiply (st[i * 2 + 1], st[i * 2 + 2]);
}
 
Node query (int i, int s, int e, int l, int r) {
        if (RLazy[i].first.twos || RLazy[i].first.fives || RLazy[i].second.first) {
                Node t;
                t.twos = csieve[RLazy[i].second.second].twos - csieve[RLazy[i].second.first - 1].twos;
                t.fives = csieve[RLazy[i].second.second].fives - csieve[RLazy[i].second.first - 1].fives;
                st[i] = multiply (t, fast_pow (RLazy[i].first, e - s + 1));
 
                if (s != e) {
                        MLazy[i * 2 + 1].first = MLazy[i * 2 + 2].first = zero;
                        RLazy[i * 2 + 1].first = RLazy[i * 2 + 2].first = RLazy[i].first;
                        RLazy[i * 2 + 1].second.first = RLazy[i].second.first;
                        RLazy[i * 2 + 2].second.second = RLazy[i].second.second;
                        int mid = (RLazy[i].second.first + RLazy[i].second.second) / 2;
                        RLazy[i * 2 + 1].second.second = mid;
                        RLazy[i * 2 + 2].second.first = mid + 1;
                }
                RLazy[i].first = zero;
		RLazy[i].second.first = 0;
        }
 
        if (MLazy[i].first.twos || MLazy[i].first.fives) {
                st[i] = multiply (st[i], fast_pow (MLazy[i].first, e - s + 1));
                if (s != e) {
                        MLazy[i * 2 + 1].first = multiply (MLazy[i * 2 + 1].first, MLazy[i].first);
                        MLazy[i * 2 + 2].first = multiply (MLazy[i * 2 + 2].first, MLazy[i].first);
                }
                MLazy[i].first = zero;
        }
 
 
	if (e < s || e < l || s > r)
		return zero;
 
        if (s >= l && e <= r)
                return st[i];
 
        int mid = (s + e) / 2;
        return multiply (query (i * 2 + 1, s, mid, l, r), query (i * 2 + 2, mid + 1, e, l, r));
}
 
void build () {
	for (long long i = 2; i < 100001; ++i) {
		sieve[i] = get5sand2s (i);
		csieve[i] = multiply (csieve[i - 1], sieve[i]);
	}
}
 
int main () {
	ios_base::sync_with_stdio (false), cin.tie (NULL);
	build();
	
	int t;
	cin >> t;
	while (t--) {
		int n, m, q, l, r;
		long long v, s = 0;
		cin >> n >> m;
		for (int i = 0; i < n; ++i) {
			cin >> v;
			if (v < 100001) {
				a[i] = sieve[v];
				continue;
			}
			a[i] = get5sand2s (v);
		}
		construct(0, 0, n - 1);
		for (int i = 0; i < m; ++i) {
			cin >> q >> l >> r;
			Node t;
			if (q != 3) {
				cin >> v;
				v < 100001 ? t = sieve[v] : t = get5sand2s (v);	
				if (q == 1) 
					update (0, 0, n - 1, l - 1, r - 1, t, true);
				if (q == 2) 
					update (0, 0, n - 1, l - 1, r - 1, t, false);
				//cout << query(0, 0, n - 1, l - 1, r - 1).twos << ' ' << query(0, 0, n - 1, l - 1, r - 1).fives << '\n';
			}
			else {
				t = query (0, 0, n - 1, l - 1, r - 1);
				//cout << t.twos << ' ' << t.fives << '\n';
				s += min (t.twos, t.fives);	
			}
		}
		cout << s << '\n';
		for (int i = 0; i < 300005; ++i) {
			MLazy[i].first = RLazy[i].first = zero;
			RLazy[i].second.first = 0;
		}
	}
	return 0;
}
