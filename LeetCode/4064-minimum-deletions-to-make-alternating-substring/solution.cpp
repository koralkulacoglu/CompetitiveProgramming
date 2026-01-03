struct Node {
    int aa;
    int ab;
    int ba;
    int bb;
};

int INF = -1e9;

template<class T> struct Seg {
	const T ID = {INF, INF, INF, INF};
	int n;
	vector<T> seg;

	T comb(T a, T b) {
        T res;

        res.aa = max({a.aa, b.aa, a.aa + b.ba, a.ab + b.aa});
        res.ab = max({a.ab, b.ab, a.aa + b.bb, a.ab + b.ab});
        res.ba = max({a.ba, b.ba, a.ba + b.ba, a.bb + b.aa});
        res.bb = max({a.bb, b.bb, a.ba + b.bb, a.bb + b.ab});
        
        return res;
	}

	void init(int _n) {
		n = _n;
		seg.assign(2*n,ID);
	}

	void pull(int p) {
		seg[p] = comb(seg[2*p], seg[2*p+1]);
	}

	void upd(int p, char val) {
        p += n;
        if (val == 'A') seg[p] = {1, INF, INF, INF};
        else seg[p] = {INF, INF, INF, 1};
		for (p /= 2; p; p /= 2) pull(p);
	}

	int query(int l, int r) {
		T ra = ID, rb = ID;
        bool raExists=false, rbExists=false;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) {
                if (!raExists) {
                    ra = seg[l];
                    raExists = true;
                }
                else ra = comb(ra,seg[l]);
                l++;
            }
			if (r&1) {
                r--;
                if (!rbExists) {
                    rb = seg[r];
                    rbExists = true;
                }
                else rb = comb(seg[r],rb);
            }
		}

        if (!raExists) return max({rb.aa, rb.ab, rb.ba, rb.bb});
        if (!rbExists) return max({ra.aa, ra.ab, ra.ba, ra.bb});
        
        T res = comb(ra, rb);

        return max({res.aa, res.ab, res.ba, res.bb});
    }
};

class Solution {
public:
    vector<int> minDeletions(string s, vector<vector<int>>& queries) {
        // could be segtree
        // we can 'combine' 2 segments by keeping track of what letter the alternation starts at

        int n = s.size();

        Seg<Node> st;
        st.init(n);
        for (int i=0; i<n; i++) st.upd(i, s[i]);

        vector<int> res;
        for (auto& query : queries) {
            int op = query[0];
            if (op == 1) {
                int j = query[1];
                s[j] = (s[j] == 'A' ? 'B' : 'A');
                st.upd(j, s[j]);
            }
            else {
                int l = query[1];
                int r = query[2];
                int curRes = st.query(l, r);
                res.push_back((r - l + 1) - curRes);
            }
        }

        return res;
    }
};

