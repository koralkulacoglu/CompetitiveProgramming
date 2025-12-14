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
	vs c(3), g(3);
	FOR (i, 0, 3) cin >> c[i];
	FOR (i, 0, 3) cin >> g[i];

	int cor=0;
	unordered_map<char, int> f1;
	unordered_map<char, int> f2;
	FOR (i, 0, 3) {
		FOR (j, 0, 3) {
			if (c[i][j] == g[i][j]) {
				cor++;
			}
			else {
				f1[c[i][j]]++;
				f2[g[i][j]]++;
			}
		}
	}
	int wrong=0;
	trav (i, f1) {
		if (f2[i.fir]) {
			wrong += min(f2[i.fir], i.sec);
		}
	}
	cout << cor << nl << wrong << nl;
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

