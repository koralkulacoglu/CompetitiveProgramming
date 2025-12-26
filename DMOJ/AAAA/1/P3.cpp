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
 
void solve1() {
	int n; cin >> n;
	vi h(n); FOR (i, 0, n) cin >> h[i];

	unordered_map<int, vi> heightIdxs;
	FOR (i, 0, n) heightIdxs[h[i]].pb(i);

	int islands = 0;
    FOR (i, 0, n) {
        if (h[i] > 0 && (i == 0 || h[i-1] == 0)) {
            islands++;
        }
    }

	cout << islands << ' ';

	FOR (c, 1, n) {
		vi idxs = heightIdxs[c];
		trav (idx, idxs) {
			bool leftLand = (idx > 0 && h[idx-1] != 0);
            bool rightLand = (idx < n-1 && h[idx+1] != 0);
			h[idx] = 0;
			if (leftLand && rightLand) islands++;
            else if (!leftLand && !rightLand) islands--;
		}
		cout << islands << ' ';
	}
	cout << nl;
}

// idea: go backwards

void solve2() {
	int n; cin >> n;
	vi c(n+2); FOR (i, 1, n+1) cin >> c[i];

	ll needed = 0;
	int cur = 0;
	FORd (i, n+1, 1) {
		int diff = c[i] - cur;
		if (diff > 0) needed += diff;
		else if (diff < 0) needed -= diff;
		cur = c[i];
	}

	int zerosNeeded = max(0, c[1] - 1);
	needed += zerosNeeded;

	if (needed > n) {
		cout << -1 << nl;
		return;
	}

	vector<list<int>> islands;
	int extra = n - needed;
	cur = 0;
	FORd (i, n+1, 1) {
		while (cur < c[i]) {
			islands.pb({i});
			cur++;
		}

		while (cur > c[i]) {
			if (sz(islands) < 2) {
				cout << -1 << nl;
				return;
			}

			islands[sz(islands)-2].pb(i);
			islands[sz(islands)-2].splice(islands[sz(islands)-2].end(), islands.back());
			islands.pop_back();
			cur--;
		}

		while (extra > 0 && !islands.empty()) {
			islands[0].pb(i);
			extra--;
		}
	}

	bool first = true;
	while (extra > 0) {
		if (!first) cout << " ";
		cout << "0";
		first = false;
		extra--;
	}

	trav (island, islands) {
		if (!first) cout << "0 ";
		first = false;
		trav (height, island) cout << height << ' ';
	}
	cout << nl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);
 
    int T = 1;
	cin >> T;
	if (T == 1) solve1();
	else solve2();
 
	return 0;
}

