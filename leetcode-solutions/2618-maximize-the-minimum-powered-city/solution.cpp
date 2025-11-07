struct SegTree {
    int n;
    vector<long long> tree, lazy;

    SegTree() {}
    SegTree(const vector<long long>& a) { init(a); }

    void init(const vector<long long>& a) {
        n = (int)a.size();
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        build(1, 0, n - 1, a);
    }

    void build(int node, int l, int r, const vector<long long>& a) {
        if (l == r) {
            tree[node] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(node * 2, l, mid, a);
        build(node * 2 + 1, mid + 1, r, a);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }

    void apply(int node, long long val) {
        tree[node] += val;
        lazy[node] += val;
    }

    void push(int node) {
        if (lazy[node] != 0) {
            apply(node * 2, lazy[node]);
            apply(node * 2 + 1, lazy[node]);
            lazy[node] = 0;
        }
    }

    void range_add(int node, int l, int r, int ql, int qr, long long val) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            apply(node, val);
            return;
        }
        push(node);
        int mid = (l + r) / 2;
        range_add(node * 2, l, mid, ql, qr, val);
        range_add(node * 2 + 1, mid + 1, r, ql, qr, val);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }

    long long point_query(int node, int l, int r, int idx) {
        if (l == r) return tree[node];
        push(node);
        int mid = (l + r) / 2;
        if (idx <= mid) return point_query(node * 2, l, mid, idx);
        else return point_query(node * 2 + 1, mid + 1, r, idx);
    }

    void range_add(int l, int r, long long val) {
        if (l > r) return;
        range_add(1, 0, n - 1, l, r, val);
    }

    long long point_query(int idx) {
        return point_query(1, 0, n - 1, idx);
    }
};

class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = (int)stations.size();
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (long long)stations[i];
        }

        vector<long long> power(n);
        for (int i = 0; i < n; i++) {
            int L = max(0, i - r);
            int R = min(n - 1, i + r);
            power[i] = pref[R + 1] - pref[L];
        }

        long long maxInit = 0;
        for (auto x : power) maxInit = max(maxInit, x);
        long long low = 0;
        long long high = maxInit + k;
        long long ans = 0;

        auto can = [&](long long X) -> bool {
            SegTree seg(power);
            long long remaining = k;

            for (int i = 0; i < n; i++) {
                long long cur = seg.point_query(i);
                if (cur < X) {
                    long long need = X - cur;
                    if (need > remaining) return false;
                    remaining -= need;

                    int pos = min<long long>(i + r, n - 1);
                    int L = max(0, pos - r);
                    int R = min(n - 1, pos + r);

                    seg.range_add(L, R, need);
                }
            }
            return true;
        };

        while (low <= high) {
            long long mid = (low + high) / 2;
            if (can(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};

