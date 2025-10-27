#include <bits/stdc++.h>
 
using namespace std;

void solve() {
	int n; cin >> n;
	vector<long long> a(n);
	long long mn=1e18;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		mn = min(mn, a[i]);
	}
	if (n==1) {
		cout << 0 << '\n';
		return;
	}
	if (n==2) {
		cout << (-1*(a[0]!=a[1])) << '\n';
		return;
	}

	// feed the left cow each iteration
	long long ans=0;
	for (int i=0; i<n-1; i++) {
		long long diff = a[i] - mn;
		a[i] -= diff;
		a[i+1] -= diff;
		ans += diff*2;

		if ((a[i]<0) || (a[i+1]<0)) {
			cout << -1 << '\n';
			return;
		}

		if (a[i+1] < mn) {
			if (i%2) {
				ans += (i+1)*(mn-a[i+1]);
				mn = a[i+1];
			}
			else {
				cout << -1 << '\n';
				return;
			}
		}
	}
	cout << ans << '\n';
}
 
int main() {
    int T;
	cin >> T;
    while(T--) {
        solve();
    }
 
	return 0;
}

