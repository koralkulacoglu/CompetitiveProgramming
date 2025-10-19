/*
ID: Koral Kulacoglu
TASK: test
LANG: C++                 
*/

#include <unordered_map>
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

// idea: simulate the game (n <= 6e5)
// if we end up with AA, BB, do we win?
// the last A/B index matters
//
// ABABBAB
//
// if we ever eat A/B with no A/B following it we lose
// we can also remove the other person's A/B pairs
//
// always take the first A/B
 
void solve() {
	int n; cin >> n;
	string s; cin >> s;

	int L=0, R=n-1;
	int pA=R-1, pB=L+1;

	auto findRightAA = [&]() {
		if (pA > R-1) pA = R-1;
		while (pA >= L && !(s[pA] == 'A' && s[pA+1] == 'A')) pA--;
	};

	auto findLeftBB = [&]() {
		if (pB < L+1) pB = L+1;
		while (pB <= R && !(s[pB-1] == 'B' && s[pB] == 'B')) pB++;
	};

	findRightAA();
	findLeftBB();

	while (L <= R) {
		if (s[R] == 'A') {
			cout << "Alice" << nl;
			return;
		}

		findRightAA();

		if (pA >= L) {
			L = pA + 1;
			if (pB < L+1) pB = L + 1;
		}
		else {
			cout << "Bob" << nl;
			return;
		}

		if (L > R) break;

		if (s[L] == 'B') {
			cout << "Bob" << nl;
			return;
		}

		findLeftBB();

		if (pB <= R) {
			R = pB - 1;
			if (pA > R-1) pA = R - 1;
		}
		else {
			cout << "Alice" << nl;
			return;
		}
	}

	cout << "Alice" << nl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);
 
    int T = 1;
	cin >> T;
	FOR (t, 1, T+1) {
		cout << "Case #" << t << ": ";
        solve();
    }
 
	return 0;
}

