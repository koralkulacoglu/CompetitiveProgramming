struct Node {
    int  sz = 0;
    long long peaks = 0;
    long long pre = 0;
    long long suf = 0;
    bool clean = true;
    int Lv0=0, Lv1=0;
    int Rv0=0, Rv1=0;
    Node() {}
    Node(int x): sz(1),pre(1),suf(1),Lv0(x),Lv1(x),Rv0(x),Rv1(x) {}
};

template<class T> struct Seg {
	const T ID = Node();
	int n;
	vector<T> seg;

    T comb(const T& a, const T& b) {
        if (!a.sz) return b;
        if (!b.sz) return a;
        Node c;
        c.sz  = a.sz + b.sz;
        c.Lv0 = a.Lv0;  c.Lv1 = (a.sz >= 2 ? a.Lv1 : b.Lv0);
        c.Rv0 = b.Rv0;  c.Rv1 = (b.sz >= 2 ? b.Rv1 : a.Rv0);

        bool pMid  = (a.sz >= 2) && a.Rv1 < a.Rv0 && a.Rv0 > b.Lv0;
        bool pMid1 = (b.sz >= 2) && a.Rv0 < b.Lv0 && b.Lv0 > b.Lv1;

        long long aFree = pMid  ? 1 : a.suf;
        long long bFree = pMid1 ? 1 : b.pre;
        c.peaks = a.peaks + b.peaks + (long long)a.sz * b.sz - aFree * bFree;

        bool Pa = a.clean && !pMid;
        bool Pb = b.clean && !pMid1;
        c.pre   = a.pre + (Pa ? (pMid1 ? 1 : b.pre) : 0);
        c.suf   = b.suf + (Pb ? (pMid  ? 1 : a.suf) : 0);
        c.clean = a.clean && b.clean && !pMid && !pMid1;
        return c;
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
    vector<long long> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        Seg<Node> st;
        st.init(n);

        for (int i=0; i<n; i++) st.upd(i, Node(nums[i]));

        vector<long long> res;
        for (auto& q : queries) {
            if (q[0] == 1) {
                int l = q[1];
                int r = q[2];
                res.push_back(st.query(l, r).peaks);
            }
            else {
                int index = q[1];
                int val = q[2];
                st.upd(index, Node(val));
            }
        }

        return res;
    }
};
