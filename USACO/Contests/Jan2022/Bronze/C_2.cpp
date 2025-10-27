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
	int n; cin >> n;
	vi a(n);
	int mn=1e9;
	FOR (i, 0, n) {
		cin >> a[i];
		mn = min(mn, a[i]);
	}
	ll ans=0;
	FOR (i, 0, n-1) {
		if (a[i]==mn && i!=0) continue;

		int sub = max(a[i], a[i+1])-mn;
		if (a[i]-sub < mn && i!=0) {
			sub = a[i]-mn;
		}
		a[i] -= sub;
		a[i+1] -= sub;
		ans += 2*sub;

		if (a[i] < mn) {
			mn = a[i];
			if (mn<0) {
				cout << -1 << nl;
				return;
			}
			i=0;
			continue;
		}
		mn = min(mn, a[i+1]);
		if (mn <0 ) {
			cout << -1 << nl;
			return;
		}
		
		/*
		trav (i, a) cout << i << ' ';
		cout << nl;
		*/
	}
	int f=a[0];
	trav (i, a) {
		if (i!=f || i<0) {
			cout << -1 << nl;
			return;
		}
	}
	cout << ans << nl;
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

