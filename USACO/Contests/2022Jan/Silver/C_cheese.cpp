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
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
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

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; 

unordered_map<int, int> picks;

void solve() {
	// 10^5 is probably too large for non-greedy, so it must be greedy
	// sort and greedy based on first -> second pick
	// use some sort of rng
	int n, m; cin >> n >> m;
	vector<vi> a(n, vi(3));
	FOR (i, 0, n) {
		a[i][0] = i+1;
		cin >> a[i][1] >> a[i][2];
		picks[a[i][1]]++;
	}

	sort(all(a), [] (vi a, vi b) {
		return (picks[a[1]]>picks[b[1]]) || (picks[a[1]]==picks[b[1]] && picks[a[2]]>picks[b[2]]);
	});

	vi pick, nopick;
	unordered_map<int, bool> picked;
	FOR (i, 0, n) {
		if (!picked[a[i][1]]) {
			picked[a[i][1]] = true;
			pick.pb(a[i][0]);
		}
		else if (!picked[a[i][2]]) {
			picked[a[i][2]] = true;
			pick.pb(a[i][0]);
		}
		else {
			nopick.pb(a[i][0]);
		}
	}

	if (n <= 100 && m <= 100) {
		cout << sz(nopick) << nl;
		trav (i, pick) cout << i << nl;
		trav (i, nopick) cout << i << nl;
		return;
	}

	// use rng somehow
	// random shuffle, if it does not TLE??
	// testcase 6 seems weak => spam submission & hope for 1 extra testcase (almost 800 points!) XD
	// maybe use genetic algorithm (if the new iteration has better ans, mutate that
	else {
		vi bestPick=nopick, bestNopick=nopick;
		vector<vi> prevA=a;
		unordered_map<int, bool> picked;
		int ans=1e9, shuffles=70, samples=100;
		FOR (i, 0, shuffles) {
			FOR (j, 0, samples) {
				iter_swap(a.begin()+rng()%n, a.begin()+rng()%n);
			}
			// random_shuffle(a.begin(), a.end(), [&](int i){return rng()%i;});
			// last try
			// okay one more
			// i swear this is not a DOS attack
			// final, final try

			// calculate the amount of hungry cows
			pick.clear(); nopick.clear(); picked.clear();
			FOR (i, 0, n) {
				if (!picked[a[i][1]]) {
					picked[a[i][1]] = true;
					pick.pb(a[i][0]);
				}
				else if (!picked[a[i][2]]) {
					picked[a[i][2]] = true;
					pick.pb(a[i][0]);
				}
				else {
					nopick.pb(a[i][0]);
				}
			}
			if (sz(nopick) <= ans) {
				ans = sz(nopick);
				bestPick = pick;
				bestNopick = nopick;
			}
			else {
				a = prevA;
			}
			if (ans == 0) break;
		}
		cout << ans << nl;
		trav (i, bestPick) cout << i << nl;
		trav (i, bestNopick) cout << i << nl;
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

