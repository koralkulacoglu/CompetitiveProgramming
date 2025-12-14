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
 
void solve() {
	int n, m; cin >> n >> m;
	unordered_map<int, vector<int>> primary;
	unordered_map<int, int> count;
	unordered_map<int, vector<int>> secondary;
	unordered_map<int, int> bridge;
	unordered_map<int, int> bridge_primary;

	for (int i=1; i<m; i++) count[i]=1;

	for (int i=1; i<=n; i++) {
		int a, b; cin >> a >> b;
		primary[a].push_back(i);
		secondary[b].push_back(i);
		bridge[i] = b;
		bridge_primary[i] = a;
	}

	int ans=0;
	vector<int> order;
	for (int i=0; i<m; i++) {
		if (primary[i].size() == 0) continue;

		vector<int> current_prims = primary[i];
		unordered_map<int, vector<int>> temp;

		for (int j=0; j<current_prims.size(); j++) {
			int size = secondary[bridge[current_prims[j]]].size();
			if (temp[size].size() == 0) {
				vector<int> temp_cow;
				temp_cow.push_back(current_prims[j]);
				temp[size] = temp_cow;
			}
			else {
				temp[size].push_back(current_prims[j]);
			}
		}

		vector<int> list;
		for (auto &i : temp) {
			list.push_back(i.first);
		}
		sort(list.begin(), list.end(), greater<int>());
		for (int &j : list) {
			for (int &k : temp[j]) {
				if (count[bridge_primary[k]]!=0) {
					count[bridge_primary[k]] = 0;
					order.push_back(k);
				}
				else if (count[bridge[k]]!=0) {
					count[bridge[k]] = 0;
					order.push_back(k);
				}
				else {
					ans++;
					order.push_back(k);
				}
			}
		}
	}

	cout << ans << nl;
	for (auto &i : order) cout << i << nl;
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

