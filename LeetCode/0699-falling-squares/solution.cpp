class SparseSegtree {
  private:
    struct Node {
        int max_val = 0;
        int lazy = 0;
        int left = -1;
        int right = -1;
    };
    
    vector<Node> tree;
    const int n;
    int timer = 0;

    // Use max instead of addition
    int comb(int a, int b) { return max(a, b); }

    // Update max_val and lazy to track the highest value
    void apply(int cur, int val) {
        tree[cur].lazy = max(tree[cur].lazy, val);
        tree[cur].max_val = max(tree[cur].max_val, val);
    }

    void push_down(int cur) {
        if (tree[cur].left == -1) {
            tree[cur].left = ++timer;
            tree.push_back(Node());
        }
        if (tree[cur].right == -1) {
            tree[cur].right = ++timer;
            tree.push_back(Node());
        }
        if (tree[cur].lazy > 0) {
            apply(tree[cur].left, tree[cur].lazy);
            apply(tree[cur].right, tree[cur].lazy);
            tree[cur].lazy = 0;
        }
    }

    void range_set(int cur, int l, int r, int ql, int qr, int val) {
        if (qr < l || ql > r) { return; }
        if (ql <= l && r <= qr) {
            apply(cur, val);
        } else {
            push_down(cur);
            int m = l + (r - l) / 2;
            range_set(tree[cur].left, l, m, ql, qr, val);
            range_set(tree[cur].right, m + 1, r, ql, qr, val);
            tree[cur].max_val =
                comb(tree[tree[cur].left].max_val, tree[tree[cur].right].max_val);
        }
    }

    int range_max(int cur, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) { return 0; }
        if (ql <= l && r <= qr) { return tree[cur].max_val; }
        push_down(cur);
        int m = l + (r - l) / 2;
        return comb(range_max(tree[cur].left, l, m, ql, qr),
                    range_max(tree[cur].right, m + 1, r, ql, qr));
    }

  public:
    SparseSegtree(int n, int q = 0) : n(n) {
        if (q > 0) { tree.reserve(2 * q * 30); } // Reserve space to avoid reallocation issues
        tree.push_back(Node());
    }

    void range_set(int ql, int qr, int val) { range_set(0, 0, n - 1, ql, qr, val); }

    int range_max(int ql, int qr) { return range_max(0, 0, n - 1, ql, qr); }
};

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n = positions.size();
        SparseSegtree st(1e9, n);
        vector<int> res;
        int mx = 0;
        for (vector<int>& pos : positions) {
            int left = pos[0];
            int sideLength = pos[1];
            int prevHeight = st.range_max(left, left + sideLength - 1);
            int newHeight = prevHeight + sideLength;
            mx = max(mx, newHeight);
            st.range_set(left, left + sideLength - 1, newHeight);
            res.push_back(mx);
        }
        return res;
    }
};
