#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
const char nl = '\n';

unordered_map<int, int> freq;
bool compare(vector<int> a, vector<int> b) {
	if (freq[a[1]] > freq[b[1]]) return true;
	if (freq[a[1]] == freq[b[1]]) {
		if (freq[a[2]] > freq[b[2]]) return true;
	}
	return false;
}
 
void solve() {
	// arr: idx, p1, p2
	// sort by frequency of p1, p2
	int n, m; cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(3));
	for (int i=0; i<n; i++) {
		a[i][0] = i+1;
		cin >> a[i][1] >> a[i][2];
		freq[a[i][1]]++;
	}
	sort(a.begin(), a.end(), compare);
	vector<int> answers, fails;
	unordered_map<int, bool> picked;
	for (int i=0; i<n; i++) {
		if (!picked[a[i][1]]) {
			picked[a[i][1]] = true;
			answers.push_back(a[i][0]);
		}
		else if (!picked[a[i][2]]) {
			picked[a[i][2]] = true;
			answers.push_back(a[i][0]);
		}
		else {
			fails.push_back(a[i][0]);
		}
	}
	cout << fails.size() << nl;
	for (int &i : answers) cout << i << nl;
	for (int &i : fails) cout << i << nl;
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

