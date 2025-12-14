#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	vector<string> c(3), g(3);
	for (int i=0; i<3; i++)
		cin >> c[i];
	for (int i=0; i<3; i++)
		cin >> g[i];

	int correct=0;
	map<char, int> f1;
	map<char, int> f2;
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			if (c[i][j] == g[i][j]) {
				correct++;
			}
			else {
				f1[c[i][j]]++;
				f2[g[i][j]]++;
			}
		}
	}
	int wrong=0;
	for (auto &i : f1) {
		if (f2[i.first]) {
			wrong += min(f2[i.first], i.second);
		}
	}
	cout << correct << '\n' << wrong << '\n';
	return 0;
}

