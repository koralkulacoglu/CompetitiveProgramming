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
	stack<pair<int, int>> stk;
	stk.push({INT_MAX, 0});
	for (int i=0; i<n; i++) {
		while (true) {
			if (stk.top().first >= h[i]) {
				if (!(stk.top().first < INT_MAX)) break;
				
				/*
				cout << "CASE";
				cout << stk.top().first << ' ' << h[i] << nl;
				*/

				ans += abs(i-stk.top().second)+1;
				break;
			}

			// cout << stk.top().first << ' ' << h[i] << nl;
			ans += abs(i-stk.top().second)+1;
			stk.pop();
		}
		stk.push({h[i], i});
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

