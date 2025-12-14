#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	ifstream cin ("shuffle.in");
	ofstream cout ("shuffle.out");

	int n, ans=0;
	cin>>n;
	vector<int> cows(n);
	for (int i=0; i<n; i++) {
		cin>>cows[i];
		cows[i]--;
	}
	unordered_map<int, bool> seen, currSeen;
	for (int i=0; i<n; i++) {
		if (!seen[i]) {
			currSeen.clear();
			currSeen[i] = true;
			int j=i;
			while (true) {
				if (seen[cows[j]] || j == cows[j]) {
					ans += (j==cows[j] && !seen[j]);
					for (auto &val:currSeen) {
						seen[val.first] = val.second;
					}
					break;
				}
				else if (currSeen[cows[j]]) {
					int k=cows[j];
					while (true) {
						seen[k] = true;
						k = cows[k];
						ans++;
						if (k==cows[j]) {
							break;
						}
					}
					break;
				}
				else {
					currSeen[cows[j]] = true;
				}
				j = cows[j];
			}
		}
	}
	cout<<ans;
}
