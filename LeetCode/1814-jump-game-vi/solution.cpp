template<class T> struct Seg {
	const T ID = -1e9; T comb(T a, T b) { return max(a,b); }
	int n; vector<T> seg;
	void init(int _n) { n = _n; seg.assign(2*n,ID); }
	void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T val) {
		seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
	T query(int l, int r) {
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
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();

        Seg<int> st;
        st.init(n);
        
        vector<int> dp(n);
        dp[0] = nums[0];
        st.upd(0, dp[0]);
        for (int i=1; i<n; i++) {
            int left = max(0, i-k);
            int right = i-1;
            int maxVal = st.query(left, right);

            dp[i] = maxVal + nums[i];
            st.upd(i, dp[i]);
        }

        return dp[n-1];
    }
};

