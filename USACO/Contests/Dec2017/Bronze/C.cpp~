#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
	ifstream cin ("measurement.in");
	ofstream cout ("measurement.out");

	int n;
	cin>>n;
	vector<pair<string,int>> days(100);
	unordered_map<string, int> vals;
	int t, dt;
	string cow;
	pair<string,int> inp;
	for (int i=0; i<n; i++) {
		cin>>t>>cow>>dt;
		t--;
		inp.first = cow;
		inp.second = dt;
		days[t] = inp;
		vals[cow] = 7;
	}
	int mx, ans=0;
	string prevWinners="", winners;
	for (int t=0; t<100; t++) {
		if (!days[t].first.empty()) {
			winners = "";
			mx = 0;
			vals[days[t].first] += days[t].second;
			for (auto &val:vals) {
				mx = max(mx, val.second);
			}
			for (auto &val:vals) {
				if (val.second == mx) {
					winners += " " + val.first;
				}
			}
			if (winners != prevWinners) {
				ans++;
				prevWinners = winners;
			}
		}
	}
	cout<<ans;
}


