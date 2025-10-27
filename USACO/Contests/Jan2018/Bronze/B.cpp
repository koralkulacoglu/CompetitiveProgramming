#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ifstream cin("lifeguards.in");
	ofstream cout("lifeguards.out");

	int n, mx=0, mn=1001;
	cin>>n;
	vector<int> acc(1001, 0);
	vector<vector<int>> rgs(n, vector<int>(2));
	for (int i=0; i<n; i++) {
		cin>>rgs[i][0]>>rgs[i][1];
		mn = min(mn, rgs[i][0]);
		mx = max(mx, rgs[i][1]);
		for (int j=rgs[i][0]; j<rgs[i][1]; j++) {
			acc[j]++;
		}	
	}

	int ans=0;
	for (int i=mn; i<mx; i++) {
		if (acc[i]) {
			ans++;
		}
	}

	int cost=1001, currCost;
	for (int i=0; i<n; i++) {
		currCost = 0;
		for (int j=rgs[i][0]; j<rgs[i][1]; j++) {
			if (acc[j]==1) {
				currCost++;
			}
		}
		cost = min(cost, currCost);
	}
	cout<<ans-(cost!=1001?cost:0);
}
