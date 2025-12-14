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
	vi a(n);
	int mn=1e9;
	bool same=true;
	int num;
	FOR (i, 0, n) {
		cin >> a[i];
		mn = min(mn, a[i]);
		if (i==0) {
			num = a[i];
		}
		else if (a[i] != num) {
			same=false;
		}
	}
	if (n==1 || same) {
		cout << 0 << nl;
		return;
	}
	if (n==2) {
		if (a[0] == a[1]) {
			cout << 0 << nl;
		}
		else {
			cout << -1 << nl;
		}
		return;
	}
	else if (n%3) {
		cout << -1 << nl;
		return;
	}
	int ans=0;
	for (int i=1; i<n-1; i+=3) {
		if (a[i]<a[i-1] || a[i]<a[i+1]) {
			cout << -1 << nl;
			return;
		}
		int small = min(a[i-1], a[i+1]);
		int diff = a[i]-small;
		ans += diff*2;

		a[i] -= diff;
		if (a[i-1] == small) a[i+1] -= diff;
		else a[i-1] -= diff;

		if (a[i]!=a[i-1] && a[i]!=a[i+1]) {
			cout << -1 << nl;
			return;
		}

		int sm = min(a[i-1], a[i+1]);
		int lg = max(a[i-1], a[i+1]);

		ans += (lg-sm)*2;
		FOR (j, -1, 2) {
			if (a[i+j] == lg) {
				a[i+j] = sm;
			}
		}
		if (!(a[i]==a[i-1] && a[i]==a[i+1]) || a[i]<0) {
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

