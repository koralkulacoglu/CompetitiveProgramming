#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
const char nl = '\n';
 
void solve() {
	ll a, b; cin >> a >> b;
	// try brute force first
	int ans=0;
	while (a != b) {
		if (a > b) {
			if (a%2) {
				a++;
			}
			else {
				if (abs(a-b) > abs(div-b)) {
					a = div;
				}
				else {
					ans += abs(a-b);
					break;
				}
			}
		}
		else {
			if (a%2) {
				a++;
			}
			else {
				ll mul = a*2;
				if (abs(a-b) > abs(mul-b)) {
					a = mul;
				}
				else {
					ans += abs(a-b);
					break;
				}
			}
		}

		ans++;
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

