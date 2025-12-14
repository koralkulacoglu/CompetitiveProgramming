#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
	ofstream cout ("blist.out");
	ifstream cin ("blist.in");
	
	int n,s,e;
	cin>>n;
	vector<vector<int>> c(n, vector<int>(3));
	for (int i=0; i<n; i++) {
		cin>>c[i][0]>>c[i][1]>>c[i][2];
		s = min(s, c[i][0]);
		e = max(e, c[i][1]);
	}
	int bucs=0;
	vector<int> inUse(n);
	for (int t=s; t<=e; t++) {
		for (int i=0; i<n; i++) {
			if (c[i][0] <= t && t <= c[i][1]) {
				inUse[i] = c[i][2];
			}
			else {
				inUse[i] = 0;
			}
		}
		bucs = max(bucs, accumulate(inUse.begin(), inUse.end(), 0));
	}
	cout<<bucs;
}

