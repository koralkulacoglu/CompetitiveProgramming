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

int n, m;
vector<vi> grid;
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};

struct DSU {
	vector<int> parents, sizes;

	DSU(int n=2e5) : parents(n), sizes(n, 1) {
		for (int i=0; i<n; i++) parents[i] = i;
	}

	int find(int x) {
		return parents[x] == x ? x : (parents[x] = find(parents[x]));
	}

	bool unite(int x, int y) {
		int x_root = find(x);
		int y_root = find(y);
		if (x_root == y_root) return false;

		sizes[x_root] += sizes[y_root];
		parents[y_root] = x_root;

		return true;
	}

	bool connected(int x, int y) {
		return find(x) == find(y);
	}
};

// idea: make holes parents in DSU
 
void solve() {
	cin >> n >> m;
	grid.resize(n, vi(m));
	FOR (i, 0, n) {
		FOR (j, 0, m) cin >> grid[i][j];
	}

	DSU dsu(n*m);
	vector<vi> seen(n, vi(m, false));

	auto bfs = [&](int startX, int startY) {
		seen[startX][startY] = true;
		queue<pi> que; que.push({startX, startY});
		while (!que.empty()) {
			pi node = que.front(); que.pop();
			int x = node.fir;
			int y = node.sec;

			FOR (i, 0, 4) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (grid[nx][ny] < grid[x][y]) continue;

				if (!seen[nx][ny]) {
					seen[nx][ny] = true;
					que.push({nx, ny});
				}

				// if the node doesn't have a parent yet, connect them
				if (dsu.find(nx * m + ny) == nx * m + ny) {
					dsu.unite(x * m + y, nx * m + ny);
				}
			}
		}
	};

	FOR (i, 0, n) {
		FOR (j, 0, m) {
			if (seen[i][j]) continue;
			bfs(i, j);
		}
	}

	int holes = 0;
	FOR (i, 0, n*m) holes += (dsu.find(i) == i);

	cout << holes << nl;

	int q; cin >> q;
	FOR (i, 0, q) {
		int r, c, x; cin >> r >> c >> x; r--; c--;
		int prevVal = grid[r][c];
		int newVal = prevVal - x;
		int parent = dsu.find(r * m + c);
		grid[r][c] = newVal;

		// find out # of unique parents of neighbors
		set<int> parents;
		FOR (j, 0, 4) {
			int nr = r + dx[i];
			int nc = c + dy[i];
			if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;

			int neighVal = grid[nr][nc];

			// TODO: fix this with seg tree or something
			if (prevVal > neighVal && newVal <= neighVal) {
				int neighParent = dsu.find(nr * m + nc);
				if (neighParent == parent) continue;

				dsu.unite(r * m + c, nr * m + nc);
				parents.ins(neighParent);
			}
		}

		holes -= sz(parents);

		cout << holes << nl;
	}
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);
 
    int T = 1;
	cin >> T;
    while(T--) {
        solve();
    }
 
	return 0;
}

