#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ifstream cin ("homework.in");
	ofstream cout ("homework.out");

	int n, sm=0;
	cin>>n;
	vector<int> hw(n);
	for (int i=0; i<n; i++) {
		cin>>hw[i];
		sm += hw[i];
	}
	vector<int> low(n);
	low[n-1] = hw[n-1];
	for (int i=n-2; i>=0; i--) {
		low[i] = min(low[i+1], hw[i]);
	}

	vector<int> kvals;
	float maxScore=0, curr, size=n-1;
	for (int k=0; k<n-2; k++) {
		sm -= hw[k];
		size--;
		curr = (sm-low[k+1])/size;
		if (curr == maxScore) {
			kvals.push_back(k+1);
		} else if (curr > maxScore) {
			kvals.clear();
			kvals.push_back(k+1);
			maxScore = curr;
		}
	}
	for (int i:kvals) cout<<i<<'\n';
}
