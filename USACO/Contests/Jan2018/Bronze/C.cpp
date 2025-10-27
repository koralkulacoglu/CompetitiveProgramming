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

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define trav(a,x) for (auto& a : x)
#define fir first
#define sec second

const char nl = '\n';

void solve() {
	// at each segment, bring the max down to the min
	int n; cin >> n;
	vi h(n);
	int mn=1e9;
	FOR (i, 0, n) {
		cin >> h[i];
		mn = min(mn, h[i]);
	}
	int ans=0;
	FOR (i, 0, n-1) {
		int d = min(h[i], h[i+1]);
		mn = min(mn, d);
		ans += mn;
		h[i+1] -= mn;
	}
	if (ans==0 || ans%2) {
		cout << -1 << nl;
	}
	else {
		cout << ans+4 << nl;
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

