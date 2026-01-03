struct SegTree {
    int n;
    vector<int> mx;

    SegTree(const vector<int>& a) {
        n = (int)a.size();
        mx.resize(4 * n);
        build(1, 0, n - 1, a);
    }

    void build(int node, int l, int r, const vector<int>& a) {
        if (l == r) {
            mx[node] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(node << 1, l, mid, a);
        build(node << 1 | 1, mid + 1, r, a);
        mx[node] = max(mx[node << 1], mx[node << 1 | 1]);
    }

    int firstPos(int need) { return firstPos(1, 0, n - 1, need); }

    int firstPos(int node, int l, int r, int need) {
        if (mx[node] < need) return -1;
        if (l == r) return l;
        int mid = (l + r) >> 1;
        int res = firstPos(node << 1, l, mid, need);
        if (res != -1) return res;
        return firstPos(node << 1 | 1, mid + 1, r, need);
    }

    void update(int idx, int val) { update(1, 0, n - 1, idx, val); }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            mx[node] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if (idx <= mid) update(node << 1, l, mid, idx, val);
        else            update(node << 1 | 1, mid + 1, r, idx, val);
        mx[node] = max(mx[node << 1], mx[node << 1 | 1]);
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        SegTree seg(baskets);

        int unplaced = 0;
        for (int need : fruits) {
            int pos = seg.firstPos(need);
            if (pos == -1) {
                ++unplaced;
            } else {
                seg.update(pos, -1);
            }
        }
        return unplaced;
    }
};
