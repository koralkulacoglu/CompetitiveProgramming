template<class T> struct Seg {
	const T ID = make_pair(1e9, -1e9);
	int n;
	vector<T> seg;
	
	T comb(T a, T b) {
		return make_pair(min(a.first, b.first), max(a.second, b.second));
	}

	void init(int _n) {
		n = _n;
		seg.assign(2*n,ID);
	}

	void pull(int p) {
		seg[p] = comb(seg[2*p], seg[2*p+1]);
	}

	void upd(int p, T val) {
		seg[p += n] = val;
		for (p /= 2; p; p /= 2) pull(p);
	}

	int query(int l, int r) {
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra,seg[l++]);
			if (r&1) rb = comb(seg[--r],rb);
		}
		T res = comb(ra,rb);
        return res.second - res.first;
	}
};

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        Seg<pair<int, int>> st;
        st.init(n);
        for (int i=0; i<n; i++) st.upd(i, make_pair(nums[i], nums[i]));

        long long ans = 0;
        priority_queue<tuple<int, int, int>> pq;
        map<pair<int, int>, bool> vis;
        pq.push({st.query(0, n-1), 0, n-1});
        vis[make_pair(0, n-1)] = true;
        for (int i=0; i<k; i++) {
            if (pq.empty()) break;

            auto [value, left, right] = pq.top();
            pq.pop();

            ans += value;

            if (left >= right) continue;

            if (!vis[make_pair(left + 1, right)]) {
                pq.push({st.query(left + 1, right), left + 1, right});
                vis[make_pair(left + 1, right)] = true;
            }
            if (!vis[make_pair(left, right - 1)]) {
                pq.push({st.query(left, right - 1), left, right - 1});
                vis[make_pair(left, right - 1)] = true;
            }
        }

        return ans;
    }
};

