#include <bits/stdc++.h>
using namespace std;

template <typename T> struct SparseTable {
	int n, log2dist;
	vector<vector<T>> st;

	SparseTable(const vector<T> &v) {
		n = (int)v.size();
		log2dist = 1 + (int)log2(n);
		st.resize(log2dist);
		st[0] = v;
		for (int i = 1; i < log2dist; i++) {
			st[i].resize(n - (1 << i) + 1);
			for (int j = 0; j + (1 << i) <= n; j++) {
				st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
			}
		}
	}

	T query(int l, int r) {
		int i = (int)log2(r - l + 1);
		return min(st[i][l], st[i][r - (1 << i) + 1]);
	}
};

