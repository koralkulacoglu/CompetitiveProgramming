#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
using namespace std;

int fact(int i){
	if (i <= 1) return 1;
  	else return i*fact(i-1);
}

int main() {
	ofstream cout ("gymnastics.out");
	ifstream cin ("gymnastics.in");
	
	int k,n;
	cin>>k>>n;
	unordered_map<int,vector<int>> pl;
	int curr;
	for (int i=0; i<k; i++) {
		for (int j=0; j<n; j++) {
			cin>>curr;
			pl[curr].push_back(j);
		}
	}
	int ans=0;
	if (k > 1) {
		for (const auto &f:pl) {
			for (const auto &s:pl) {
				if (f.first == s.first) {
					break;
				}
				int first=0, second=0;
				for (int ix=0; ix<n; ix++) {
					first += f.second[ix] > s.second[ix];
					second += f.second[ix] < s.second[ix];
					if (first>0 && second>0) {
						break;
					}
				}
				if (!(first>0 && second>0)) {
					ans++;
				}
			}
		}
	}
	else {
		for (int i=1; i<n; i++)
			ans += n-i;
	}

	cout<<ans;
}

