template<class T> struct Seg { // comb(ID,b) = b
	const T ID = 0; T comb(T a, T b) { return max(a,b); }
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

Seg<int> st;

class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size();
        st.init(n);
        for (int i=0; i<n; i++) st.upd(i, chargeTimes[i]);
        
        int ans = 0;
        int mx = 0;
        long long sum = 0;
        int j=0;
        for (int i=0; i<n; i++) {
            sum += runningCosts[i];
            mx = st.query(j, i);
            
            while (j < n) {
                if (mx+(i-j+1)*sum <= budget) break;
                sum -= runningCosts[j];
                j++;
                mx = st.query(j, i);
            }
            
            ans = max(ans, i-j+1);
        }
        
        return ans;
    }
};
