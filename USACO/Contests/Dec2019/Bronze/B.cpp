#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
	ofstream cout ("whereami.out");
	ifstream cin ("whereami.in");
	int n;
	string r;
	cin>>n>>r;
	for (int i=1; i<=n; i++) {
		unordered_map<string, bool> seen;
		bool works = true;
		for (int j=0; j<n; j++) {
			if (seen[r.substr(j,i)]) {
				works = false;
				break;
			} else {
				seen[r.substr(j,i)] = true;
			}
		}
		if (works) {
			cout<<i;
			return 0;
		}
	}
}

