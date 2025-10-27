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
	if (n==1) {
		cout << 0 << nl;
		return;
	}
	if (n==2) {
		cout << (-1*(a[0]!=a[1])) << nl;
		return;
	}

	// feed the left cow each iteration
	ll ans=0;
	FOR (i, 0, n-1) {
		int diff = a[i] - mn;
		a[i] -= diff;
		a[i+1] -= diff;
		ans += diff*2;

		if (a[i]<0 || a[i+1]<0) {
			cout << -1 << nl;
			return;
		}

		if (a[i+1] < mn) {
			if (i%2) {
				ans += (i+1)*(mn-a[i+1]);
				mn = a[i+1];
			}
			else {
				cout << -1 << nl;
				return;
			}
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

