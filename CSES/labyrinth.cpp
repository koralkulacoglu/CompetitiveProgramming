/*
ID: Koral Kulacoglu
TASK: test
LANG: C++                 
*/

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

vi dx = {-1, 1, 0, 0};
vi dy = {0, 0, -1, 1};
 
void solve() {
	int n, m; cin >> n >> m;
	pi start;
	vector<string> grid(n);
	FOR (i, 0, n) {
		cin >> grid[i];
		FOR (j, 0, m) {
			if (grid[i][j] == 'A') start = {i, j};
		}
	}

	vector<vpi> vis(n, vpi(m, {-2, -2}));
	vis[start.fir][start.sec] = {-1, -1};
	queue<pair<pi, pi>> q;
	q.push({{-1, -1}, start});

	auto isValid = [&](pi node) {
		if (node.fir < 0 || node.fir >= n) return false;
		if (node.sec < 0 || node.sec >= m) return false;
		if (grid[node.fir][node.sec] == '#') return false;
		if (vis[node.fir][node.sec].fir != -2) return false;
		return true;
	};

	pi B = {-1, -1};

	while (!q.empty()) {
		auto nodes = q.front(); q.pop();
		pi to = nodes.sec;

		if (grid[to.fir][to.sec] == 'B') {
			B = to;
			break;
		}

		FOR (i, 0, 4) {
			pi newTo = {to.fir + dx[i], to.sec + dy[i]};
			if (!isValid(newTo)) continue;

			vis[newTo.fir][newTo.sec] = to;
			q.push({to, newTo});
		}
	}

	if (B == make_pair(-1, -1)) {
		cout << "NO" << nl;
		return;
	}

	auto getDir = [](pi from, pi to) {
		if (to.fir > from.fir) return 'D';
		if (to.fir < from.fir) return 'U';
		if (to.sec > from.sec) return 'R';
		return 'L';
	};

	string path;
	while (vis[B.fir][B.sec] != make_pair(-1, -1)) {
		pi from = vis[B.fir][B.sec];
		pi to = B;
		char dir = getDir(from, to);
		path.pb(dir);
		B = from;
	}

	reverse(path.begin(), path.end());

	cout << "YES" << nl << sz(path) << nl << path << nl;
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

