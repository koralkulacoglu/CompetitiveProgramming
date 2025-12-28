/*
ID: Koral Kulacoglu
TASK: test
LANG: C++                 
*/

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef long double lld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;
 
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<ld> vld;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<cd> vcd;

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i, a, b) for (int i=(a)-1; i >= b; i--)
#define F0Rd(i, a) for (int i=(a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
#define ins insert
#define lbound(a, v) lower_bound(all(a), v)-a.begin()
#define ubound(a, v) upper_bound(all(a), v)-a.begin()
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a*b)/gcd(a, b)
 
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x);
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifdef DEBUG
#define dbg(x...) cerr <<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << endl;
#else
#define dbg(x...)
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct custom_hash {
    size_t operator()(uint64_t x) const {
        x ^= rng();
        return x ^ (x >> 16);
    }
};
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; 

// we need to see if we can reach each node using a path of size k given dist[i][j] = k
// some form of dijkstras???
// MST + use the component's size to determine if new dist is achievable
// maybe we can't use kruskal's
 
void solve() {
	int n; cin >> n;
	vector<vi> d(n, vi(n));
	FOR (i, 0, n) {
		FOR (j, 0, n) {
			cin >> d[i][j];
		}
	}

	FOR (i, 0, n) {
		FOR (j, 0, n) {
			if (i == j) {
				if (d[i][j] != 0) {
					cout << "NO" << nl;
					return;
				}
			}
			else if (d[i][j] == 0 || d[j][i] == 0) {
				cout << "NO" << nl;
				return;
			}

			if (d[i][j] != d[j][i]) {
				cout << "NO" << nl;
				return;
			}
		}
	}

	// fully connected tree
	// start connections using smallest edges since those always have to be DIRECTLY connected
	// when connecting 2 components we need to decide if any connection is valid
	// ignore that case for now, best solution i can think of is O(n^3)
	//
	// start from node 0 maybe??

	vector<vpll> edges(n);
	vll dist(n, 1e18);
	vi parent(n, -1);
	vector<bool> vis(n, false);
	dist[0] = 0;
	FOR (i, 0, n) {
		int x = -1;

		FOR (j, 0, n) {
			if (!vis[j] && (x == -1 || dist[j] < dist[x])) x = j;
		}

		if (dist[x] == 1e18) {
			cout << "NO" << nl;
			return;
		}

		vis[x] = true;

		if (parent[x] != -1) {
			edges[x].pb({dist[x], parent[x]});
			edges[parent[x]].pb({dist[x], x});
		}

		FOR (j, 0, n) {
			if (!vis[j] && d[x][j] < dist[j]) {
				dist[j] = d[x][j];
				parent[j] = x;
			}
		}
	}

	// now we want to calculate shortest path from any node to every other node and see if it matches the input
	// idea: we don't need dijkstras, we can actually just BFS since its a tree (no cycles)
	
	auto check = [&](int start) -> bool {
		vll dist(n, 1e18);
		dist[start] = 0;
		queue<pi> q;
		q.push({0, start});
		while (!q.empty()) {
			pi best = q.front(); q.pop();
			ll cost = best.fir;
			int node = best.sec;

			if (dist[node] > cost) continue;

			trav (neigh, edges[node]) {
				ll newCost = cost + neigh.fir;
				int newNode = neigh.sec;

				if (dist[newNode] != 1e18) continue;

				q.push({newCost, newNode});
				dist[newNode] = newCost;
			}
		}

		FOR (i, 0, n) {
			if (dist[i] != d[start][i]) return false;
		}

		return true;
	};

	FOR (i, 0, n) {
		if (!check(i)) {
			cout << "NO" << nl;
			return;
		}
	}

	cout << "YES" << nl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);
 
    int T = 1;
//    cin >> T;
    while(T--) {
        solve();
    }
 
	return 0;
}

