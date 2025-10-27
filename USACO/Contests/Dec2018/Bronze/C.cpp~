#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

set<int> ans;

void dfs(vector<int> f, vector<int> s, int ft, int st, int day) {
	if (day == 4) {
		ans.insert(ft);
		return;
	} else {
		if (day%2!=0) {
			set<int> curr(f.begin(), f.end());
			for (auto node:curr) {
				vector<int> n = f;
				vector<int> m = s;
				auto loc = find(n.begin(), n.end(), node);
				n.erase(loc);
				m.push_back(node);
				dfs(n, m, ft-node, st+node, day+1);
			}
		}
		else {
			set<int> curr(s.begin(), s.end());
			for (auto node:curr) {
				vector<int> n = f;
				vector<int> m = s;
				auto loc = find(m.begin(), m.end(), node);
				m.erase(loc);
				n.push_back(node);
				dfs(n, m, ft+node, st-node, day+1);
			}
		}
	}
}

int main() {
	ofstream cout ("backforth.out");
	ifstream cin ("backforth.in");
	
	vector<int> f, s;
	int curr;
	for (int i=0; i<10; i++) {
		cin>>curr;
		f.push_back(curr);
	}
	for (int i=0; i<10; i++) {
		cin>>curr;
		s.push_back(curr);
	}
	dfs(f, s, 1000, 1000, 0);
	cout<<ans.size();
}
