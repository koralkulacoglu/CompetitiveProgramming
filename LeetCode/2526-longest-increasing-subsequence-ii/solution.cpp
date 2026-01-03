#include <bits/stdc++.h>
using namespace std;

template<class T> struct Seg { // comb(ID,b) = b
	const T ID = 0; T comb(T a, T b) { return max(a, b); }
	int n; vector<T> seg;
	void init(int _n) { n = _n; seg.assign(2*n,ID); }
	void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T val) { // set val at position p
		seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
	T query(int l, int r) {	// min on interval [l, r]
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra,seg[l++]);
			if (r&1) rb = comb(seg[--r],rb);
		}
		return comb(ra,rb);
	}
};

class Solution {
public:
    int lengthOfLIS(vector<int>& a, int k) {
        int n = a.size();
        Seg<int> st; // set max size of subsequence for number i at each iteration
        st.init(1e5+2);
        for (int i=0; i<n; i++) {
            int val = a[i];
            int size = st.query(max(0, val-k), val-1);
            st.upd(val, size+1);
        }
        return st.query(0, 1e5+1);
    }
};
