#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 3200005; // Sufficient for 800k points * 4

// --- Global Data Structures ---
int tree_freq[MAXN];  // Count of 1s
int tree_val[MAXN];   // Hash value
bool tree_lazy[MAXN]; // Lazy flip tag
int real_len[MAXN];   // The actual length of the range
int tree_pow2[MAXN];  // Optimization: Precomputed 2^(real_len) % MOD

vector<int> coords;

// --- Helpers ---
ll binpow(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

int get_idx(int x) {
    return lower_bound(coords.begin(), coords.end(), x) - coords.begin();
}

// --- Segment Tree ---

// O(1) Push Up using precomputed powers
void push_up(int node) {
    tree_freq[node] = tree_freq[2 * node] + tree_freq[2 * node + 1];
    
    // Combine Hash: Left * 2^(RightLen) + Right
    // Use precomputed tree_pow2 for the right child's length
    tree_val[node] = (1LL * tree_val[2 * node] * tree_pow2[2 * node + 1] + tree_val[2 * node + 1]) % MOD;
}

// O(1) Apply Flip
void apply_flip(int node) {
    tree_lazy[node] = !tree_lazy[node];
    tree_freq[node] = real_len[node] - tree_freq[node];
    
    // Value becomes (AllOnes - OldValue)
    // AllOnes is 2^(len) - 1. We have 2^(len) precomputed!
    int all_ones = (tree_pow2[node] - 1 + MOD) % MOD;
    tree_val[node] = (all_ones - tree_val[node] + MOD) % MOD;
}

void push_down(int node) {
    if (!tree_lazy[node]) return;
    apply_flip(2 * node);
    apply_flip(2 * node + 1);
    tree_lazy[node] = false;
}

void build(int node, int l, int r) {
    tree_lazy[node] = false;
    tree_freq[node] = 0;
    tree_val[node] = 0;
    
    if (l == r) {
        real_len[node] = coords[l + 1] - coords[l];
        tree_pow2[node] = binpow(2, real_len[node]); // Precompute!
        return;
    }
    
    int mid = (l + r) / 2;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    
    real_len[node] = real_len[2 * node] + real_len[2 * node + 1];
    // We only need tree_pow2 for child nodes usually, but consistency is good
    // Actually strictly we only access tree_pow2[2*node+1] in push_up.
    // But apply_flip uses tree_pow2[node]. So we need it for all nodes.
    // Optimization: (2^L * 2^R) % MOD
    tree_pow2[node] = (1LL * tree_pow2[2 * node] * tree_pow2[2 * node + 1]) % MOD;
}

void update(int node, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return;
    if (ql <= l && r <= qr) {
        apply_flip(node);
        return;
    }
    push_down(node);
    int mid = (l + r) / 2;
    update(2 * node, l, mid, ql, qr);
    update(2 * node + 1, mid + 1, r, ql, qr);
    push_up(node);
}

struct NodeData {
    int freq;
    int val;
    int len;
};

NodeData query(int node, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return {0, 0, 0};
    if (ql <= l && r <= qr) {
        return {tree_freq[node], tree_val[node], real_len[node]};
    }
    
    push_down(node);
    int mid = (l + r) / 2;
    
    NodeData res_l = query(2 * node, l, mid, ql, qr);
    NodeData res_r = query(2 * node + 1, mid + 1, r, ql, qr);
    
    int combined_freq = res_l.freq + res_r.freq;
    int combined_len = res_l.len + res_r.len;
    
    // Note: We still need binpow here because 'res_r.len' is dynamic (depends on query overlap)
    // However, the number of nodes visited is small enough now that this is acceptable.
    int combined_val = (1LL * res_l.val * binpow(2, res_r.len) + res_r.val) % MOD;
    
    return {combined_freq, combined_val, combined_len};
}

int find_kth_zero(int node, int l, int r, int k) {
    if (l == r) return coords[l] + k - 1;
    
    push_down(node);
    int mid = (l + r) / 2;
    
    int zeros_left = real_len[2 * node] - tree_freq[2 * node];
    if (k <= zeros_left) return find_kth_zero(2 * node, l, mid, k);
    else return find_kth_zero(2 * node + 1, mid + 1, r, k - zeros_left);
}

// --- Main ---
struct Update { int l, r; };
struct Query { int l, r, k; };

void solve() {
    int n, m, q;
    if (!(cin >> n >> m >> q)) return;
    
    vector<Update> updates(m);
    for(int i=0; i<m; ++i) {
        cin >> updates[i].l >> updates[i].r;
        coords.push_back(updates[i].l);
        coords.push_back(updates[i].r + 1);
    }
    
    vector<Query> queries(q);
    for(int i=0; i<q; ++i) {
        cin >> queries[i].l >> queries[i].r >> queries[i].k;
        coords.push_back(queries[i].l);
        coords.push_back(queries[i].r + 1);
    }
    
    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());
    
    int M = coords.size() - 1;
    build(1, 0, M - 1);
    
    for(const auto& upd : updates) {
        update(1, 0, M - 1, get_idx(upd.l), get_idx(upd.r + 1) - 1);
    }
    
    for(const auto& qry : queries) {
        int l_idx = get_idx(qry.l);
        int r_idx = get_idx(qry.r + 1) - 1;
        
        NodeData info = query(1, 0, M - 1, l_idx, r_idx);
        int total_len = info.len;
        int total_zeros = total_len - info.freq;
        int to_delete = total_len - qry.k;
        
        if (to_delete >= total_zeros) {
            // Delete all zeros
            cout << (binpow(2, qry.k) - 1 + MOD) % MOD << "\n";
        } else {
            // Find K-th zero
            int zeros_before = 0;
            if (l_idx > 0) {
                NodeData pre = query(1, 0, M - 1, 0, l_idx - 1);
                zeros_before = pre.len - pre.freq;
            }
            
            int split_pos = find_kth_zero(1, 0, M - 1, zeros_before + to_delete + 1);
            
            // Map split_pos to interval
            int split_interval_idx = lower_bound(coords.begin(), coords.end(), split_pos) - coords.begin();
            if (split_interval_idx == coords.size() || coords[split_interval_idx] > split_pos) {
                split_interval_idx--;
            }
            
            // 1. Left Part (Before split interval)
            // Logic: All zeros deleted, so it's a string of 1s.
            // Count ones in [l_idx, split_interval_idx - 1]
            NodeData left_query = query(1, 0, M - 1, l_idx, split_interval_idx - 1);
            int left_ones = left_query.freq;
            ll left_val = (binpow(2, left_ones) - 1 + MOD) % MOD;
            
            // 2. Right Part (After split interval)
            NodeData right_query = query(1, 0, M - 1, split_interval_idx + 1, r_idx);
            
            // 3. Middle Part (Inside split interval)
            // The interval containing split_pos is ALL ZEROS.
            // Left of split_pos inside here -> deleted.
            // Right of split_pos inside here -> kept (but they are 0s).
            int mid_len = coords[split_interval_idx + 1] - split_pos;
            
            // Combine: LeftVal * 2^(MidLen + RightLen) + MidVal(0) * ... + RightVal
            int final_right_len = mid_len + right_query.len;
            ll ans = (left_val * binpow(2, final_right_len) + right_query.val) % MOD;
            
            cout << ans << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

