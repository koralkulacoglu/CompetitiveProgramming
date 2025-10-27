#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
const char nl = '\n';

void solve() {
	// ifstream cin("C_in1.txt");
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
//	cin >> T;
    while(T--) {
        solve();
    }
 
	return 0;
}

