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

vi dx = {-1, 1, 0, 0};
vi dy = {0, 0, -1, 1};
 
void solve() {
	ofstream cout ("visitfj.out");
	ifstream cin ("visitfj.in");

	int n, t; cin >> n >> t;
	vector<vi> fields(n, vi(n));
	FOR (i, 0, n) FOR (j, 0, n) cin >> fields[i][j];

	auto getNeighs = [&](vi& node) -> vector<vi> {
		int time = node[0];
		int x = node[1];
		int y = node[2];

		vector<vi> res;
		FOR (i, 0, 4) {
			FOR (j, 0, 4) {
				FOR (k, 0, 4) {
					int newX = x + dx[i] + dx[j] + dx[k];
					int newY = y + dy[i] + dy[j] + dy[k];
					if (newX < 0 || newY < 0 || newX >= n || newY >= n) continue;

					int newTime = time + 3 * t + fields[newX][newY];
					res.pb({newTime, newX, newY});
				}
			}
		}

		// if we can reach the end in <3 steps, add that
		int distToEnd = n-1 - x + n-1 - y;
		if (distToEnd < 3) res.pb({time + distToEnd * t, n-1, n-1});

		return res;
	};

	vector<vi> times(n, vi(n, 1e9)); times[0][0] = 0;
	priority_queue<vi, vector<vi>, greater<vi>> pq; pq.push({0, 0, 0});
	while (!pq.empty()) {
		vi node = pq.top(); pq.pop();
		int time = node[0];
		int x = node[1];
		int y = node[2];

		if (time > times[x][y]) continue;

		if (x == n-1 && y == n-1) {
			cout << time << nl;
			return;
		}

		vector<vi> neighs = getNeighs(node);
		trav (neigh, neighs) {
			int newTime = neigh[0];
			int newX = neigh[1];
			int newY = neigh[2];

			if (newTime >= times[newX][newY]) continue;

			times[newX][newY] = newTime;
			pq.push(neigh);
		}
	}
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

