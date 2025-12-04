#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

// Faster I/O
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int MAX_GRID = 200005; 

struct RollbackInfo {
    int type; // 0 = merge, 1 = add_leak
    int u, v; // nodes involved
    int val_u, val_v; // old values stored for rollback
    int old_sinks;
};

struct DSU_Rollback {
    vector<int> parent;
    vector<int> sz;
    vector<bool> has_leak; // true if this component drains into a smaller neighbor
    int num_sinks; // Global answer: number of components that DO NOT leak
    
    stack<RollbackInfo> history;

    DSU_Rollback(int n) {
        parent.resize(n);
        sz.assign(n, 1);
        has_leak.assign(n, false);
        // Initially, every cell is its own component and has no leak (needs a hole)
        for(int i=0; i<n; i++) parent[i] = i;
        num_sinks = n;
    }

    // Must strictly be O(log N) or O(1). No path compression allows O(1) rollback.
    int find(int i) {
        if (parent[i] == i)
            return i;
        return find(parent[i]);
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);

        if (root_i != root_j) {
            // Merge by size
            if (sz[root_i] < sz[root_j]) swap(root_i, root_j);

            // Logic:
            // We are merging two components.
            // We lose 1 component count immediately (the child root_j).
            // We need to calculate if we lose "sink" status.
            
            bool i_was_sink = !has_leak[root_i];
            bool j_was_sink = !has_leak[root_j];
            
            // Save state for rollback
            history.push({0, root_i, root_j, (int)has_leak[root_i], (int)has_leak[root_j], num_sinks});

            // If a component was a sink (no leak), it contributed +1 to num_sinks.
            // Remove both contributions, calculate new combined contribution.
            num_sinks -= (i_was_sink + j_was_sink);

            // Link j to i
            parent[root_j] = root_i;
            sz[root_i] += sz[root_j];
            
            // New leak status is OR of both
            has_leak[root_i] = has_leak[root_i] | has_leak[root_j];
            
            // Add back if the new combined component is a sink
            if (!has_leak[root_i]) num_sinks++;
        }
    }

    void add_leak(int i) {
        int root = find(i);
        // If it's already leaking, adding another leak changes nothing
        if (!has_leak[root]) {
            history.push({1, root, -1, (int)has_leak[root], -1, num_sinks});
            has_leak[root] = true;
            num_sinks--; // It was a sink, now it leaks, so count decreases
        }
    }

    void rollback(int snapshot) {
        while (history.size() > snapshot) {
            RollbackInfo info = history.top();
            history.pop();

            num_sinks = info.old_sinks;

            if (info.type == 0) { // Undo Merge
                int root_i = info.u;
                int root_j = info.v;
                
                // Restore parent pointer (unlink)
                parent[root_j] = root_j;
                
                // Restore size
                sz[root_i] -= sz[root_j];
                
                // Restore leak status
                has_leak[root_i] = (bool)info.val_u;
                has_leak[root_j] = (bool)info.val_v;
                
            } else { // Undo Add Leak
                int root = info.u;
                has_leak[root] = (bool)info.val_u;
            }
        }
    }
};

int n, m, q;
vector<pair<int, int>> edges_tree[800005]; // Segment tree for edges
vector<int> leaks_tree[800005];            // Segment tree for leaks

// Add operation to segment tree range [l, r]
void add_to_tree(int node, int start, int end, int l, int r, int u, int v, int type) {
    if (l > end || r < start) return;
    if (l <= start && end <= r) {
        if (type == 0) edges_tree[node].push_back({u, v}); // Edge u-v
        else leaks_tree[node].push_back(u);               // Leak at u
        return;
    }
    int mid = (start + end) / 2;
    add_to_tree(node * 2, start, mid, l, r, u, v, type);
    add_to_tree(node * 2 + 1, mid + 1, end, l, r, u, v, type);
}

vector<int> results;

void process_tree(int node, int start, int end, DSU_Rollback& dsu) {
    int snapshot = dsu.history.size();

    // Apply changes for this node
    for (auto& edge : edges_tree[node]) {
        dsu.unite(edge.first, edge.second);
    }
    for (int u : leaks_tree[node]) {
        dsu.add_leak(u);
    }

    if (start == end) {
        results[start] = dsu.num_sinks;
    } else {
        int mid = (start + end) / 2;
        process_tree(node * 2, start, mid, dsu);
        process_tree(node * 2 + 1, mid + 1, end, dsu);
    }

    // Rollback
    dsu.rollback(snapshot);
}

// History of values for a cell: {time, value}
vector<pair<int, int>> history[200005];

void solve() {
    if (!(cin >> n >> m)) return;

    // Reset global structures for multiple test cases
    int total_cells = n * m;
    for (int i = 0; i < total_cells; i++) {
        history[i].clear();
    }
    
    // Read initial grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int val; cin >> val;
            // Time 0: Initial Value
            history[i * m + j].push_back({0, val});
        }
    }

    cin >> q;
    // Read queries and build history
    for (int k = 1; k <= q; k++) {
        int r, c, x;
        cin >> r >> c >> x;
        r--; c--; // 0-based
        int idx = r * m + c;
        int current_val = history[idx].back().second;
        history[idx].push_back({k, current_val - x});
    }

    // Clear segment tree (only up to needed size 4*Q)
    int max_tree_idx = 4 * (q + 1); 
    for(int i=0; i<=max_tree_idx; i++) {
        edges_tree[i].clear();
        leaks_tree[i].clear();
    }

    // Helper to process intervals between two neighbors
    auto process_neighbors = [&](int u, int v) {
        int idxU = 0, idxV = 0;
        int cur_time = 0;
        
        while (cur_time <= q) {
            int valU = history[u][idxU].second;
            int valV = history[v][idxV].second;
            
            // Find when the next change happens for either u or v
            int next_time_u = (idxU + 1 < history[u].size()) ? history[u][idxU + 1].first : q + 1;
            int next_time_v = (idxV + 1 < history[v].size()) ? history[v][idxV + 1].first : q + 1;
            int end_interval = min(next_time_u, next_time_v) - 1;

            if (valU == valV) {
                // Add Edge for interval [cur_time, end_interval]
                add_to_tree(1, 0, q, cur_time, end_interval, u, v, 0);
            } else if (valU > valV) {
                // U leaks to V (U is bigger)
                add_to_tree(1, 0, q, cur_time, end_interval, u, -1, 1);
            } else {
                // V leaks to U (V is bigger)
                add_to_tree(1, 0, q, cur_time, end_interval, v, -1, 1);
            }

            cur_time = end_interval + 1;
            if (cur_time == next_time_u) idxU++;
            if (cur_time == next_time_v) idxV++;
        }
    };

    // Iterate all horizontal neighbors
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m - 1; c++) {
            int u = r * m + c;
            int v = r * m + (c + 1);
            process_neighbors(u, v);
        }
    }
    // Iterate all vertical neighbors
    for (int r = 0; r < n - 1; r++) {
        for (int c = 0; c < m; c++) {
            int u = r * m + c;
            int v = (r + 1) * m + c;
            process_neighbors(u, v);
        }
    }

    DSU_Rollback dsu(n * m);
    results.resize(q + 1);
    
    // DFS the Segment Tree
    process_tree(1, 0, q, dsu);

    for (int i = 0; i <= q; i++) {
        cout << results[i] << '\n';
    }
}

int main() {
    fast_io();
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

