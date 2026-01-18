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

template<class T> struct Seg {
    int n;
    vector<T> tree, lazy;

	void init(int _n) {
		n = _n;
		tree.assign(4*n, 0);
		lazy.assign(4*n, 1);
	}

	void push(int v, int l, int r) {
		if (lazy[v] == 1) return;

		tree[2*v] = tree[2*v] * lazy[v];
		tree[2*v] %= MOD;

		lazy[2*v] = lazy[2*v] * lazy[v];
		lazy[2*v] %= MOD;

		tree[2*v+1] = tree[2*v+1] * lazy[v];
		tree[2*v+1] %= MOD;

		lazy[2*v+1] = lazy[2*v+1] * lazy[v];
		lazy[2*v+1] %= MOD;

		lazy[v] = 1;
	}

	void pull(int v) {
		tree[v] = tree[2*v] + tree[2*v+1];
		tree[v] %= MOD;
	}

	void upd(int v, int l, int r, int ql, int qr, T val) {
		if (l > qr || r < ql) return;

        if (l >= ql && r <= qr) {
            tree[v] = (tree[v] * val) % MOD;
            lazy[v] = (lazy[v] * val) % MOD;
            return;
        }

        push(v, l, r);

        int mid = (l + r) / 2;

        upd(2 * v, l, mid, ql, qr, val);
        upd(2 * v + 1, mid + 1, r, ql, qr, val);

        pull(v);
	}

	void set(int v, int l, int r, int idx, T val) {
        if (l == r) {
            tree[v] = val;
            lazy[v] = 1; 
            return;
        }

        push(v, l, r);

        int mid = (l + r) / 2;

        if (idx <= mid) set(2 * v, l, mid, idx, val);
        else set(2 * v + 1, mid + 1, r, idx, val);

        pull(v);
    }

	T query(int v, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) return 0;
        if (l >= ql && r <= qr) return tree[v];

        push(v, l, r);

        int mid = (l + r) / 2;

        return (query(2 * v, l, mid, ql, qr) + query(2 * v + 1, mid + 1, r, ql, qr)) % MOD;
    }

    void upd_range(int l, int r, T val) { upd(1, 0, n - 1, l, r, val); }

    void set_point(int p, T val) { set(1, 0, n - 1, p, val); }

    T query_range(int l, int r) { return query(1, 0, n - 1, l, r); }
};
 
void solve() {
	int n, d; cin >> n >> d;
	vpi cows(n);
	vi pos(n);
	FOR (i, 0, n) {
		cin >> cows[i].fir >> cows[i].sec;
		pos[i] = cows[i].fir;
	}

	Seg<ll> st;
	st.init(n);

	FOR (i, 0, n) {
		if (cows[i].sec == 1) {
			ll ways = st.query_range(0, i-1) + 1;
			ways %= MOD;
			st.set_point(i, ways);
		}
		else {
			int idx = lower_bound(all(pos), cows[i].fir - d) - pos.begin();
			if (idx < i) st.upd_range(idx, i-1, 2);
		}
	}

	ll ans = st.query_range(0, n - 1);

	cout << ans << nl;
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

