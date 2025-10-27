#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
const char nl = '\n';
 
void solve() {
	int n; cin >> n;
	vector<int> h(n);
	for (int i=0; i<n; i++) cin >> h[i];

	ll ans=0;
	for (int i=0; i<n-1; i++) {
		int cMin = min(h[i], h[i+1]);
		int cMax = min(h[i], h[i+1]);
		for (int j=i+1; j<n; j++) {
			if (cMin > h[i]) {
				cMin = h[i];
				continue;
			}
			if (cMax > h[j]) {
				continue;
			}
			else {
				ans += j-i+1;
				cMax = h[j];
				if (h[i] < h[j]) break;
			}
			if (h[i] < h[j]) {
				ans += j-i+1;
				break;
			}
		}
	}
	cout << ans << nl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);
 
    int T = 1;
//	cin >> T;
    while(T--) {
        solve();
    }
 
	return 0;
}
