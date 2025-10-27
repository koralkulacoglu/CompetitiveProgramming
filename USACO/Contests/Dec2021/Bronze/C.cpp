#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<vector<char>> m;
int count=0, n;
void dfs(int i, int j, int k, int down) {
	if (i==n-1 && j==n-1) {
		count++;
		return;
	}
	if (i==0 && j==0) {
		if (m[i+1][j]=='.') {
			dfs(i+1, j, k, true);
		}
		if (m[i][j+1]=='.') {
			dfs(i, j+1, k, false);
		}
	}
	else {
		if (i!=n-1 && m[i+1][j]=='.') {
			if (!down && k>0) {
				dfs(i+1, j, k-1, !down);
			} else if (down) {
				dfs(i+1, j, k, down);
			}
		}
		if (j!=n-1 && m[i][j+1]=='.') {
			if (down && k>0) {
				dfs(i, j+1, k-1, !down);
			} else if (!down) {
				dfs(i, j+1, k, down);
			}
		}
	}
}

int main() {
	int T;
	cin>>T;
	for (int t=0; t<T; t++) {
		int k;
		cin>>n>>k;
		for (int i=0; i<n; i++) {
			vector<char> curr;
			char val;
			for (int j=0; j<n; j++) {
				cin>>val;
				curr.push_back(val);
			}
			m.push_back(curr);
		}
		count = 0;
		dfs(0, 0, k, false);
		cout<<count<<'\n';
		m.clear();
	}
}

