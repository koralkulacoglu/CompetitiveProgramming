/*
ID: Koral Kulacoglu
TASK: Shiori Miyagi and Maximum Array Score
LANG: C++                 
*/

#pragma GCC optimize ("O3")
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORd(i, a, b) for (int i=(a)-1; i >= b; i--)
#define all(x) x.begin(), x.end()
 
const char nl = '\n';

const int MAXM = 200005;
ll tree_arr[4 * MAXM];
int N_tree;

void build(int node, int start, int end) {
    tree_arr[node] = 0;
    if (start == end) return;
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
}

void update(int node, int start, int end, int idx, ll val) {
    if (start == end) {
        tree_arr[node] = max(tree_arr[node], val);
        return;
    }
    int mid = (start + end) / 2;
    if (start <= idx && idx <= mid) update(2 * node, start, mid, idx, val); 
    else update(2 * node + 1, mid + 1, end, idx, val);
    tree_arr[node] = max(tree_arr[2 * node], tree_arr[2 * node + 1]);
}

ll query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return tree_arr[node];
    int mid = (start + end) / 2;
    return max(query(2 * node, start, mid, l, r), query(2 * node + 1, mid + 1, end, l, r));
}

// v(b, x) is the exponent of b in x
int get_v(int b, int x) {
    int cnt = 0;
    while (x > 0 && x % b == 0) {
        cnt++;
        x /= b;
    }
    return cnt;
}

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    // Clean tree for new test case
    // Only need to cover range [0, m]
    N_tree = m + 1;
    build(1, 0, N_tree);

    // Iterate i from n down to 2
    // Using transformation a_i = b_i + i, where 0 <= b_2 <= ... <= b_n <= m - n
    // But actually b_i can go up to m - i.
    // The bounds are 0 <= b_i <= m - i.
    // Since we query range [b, m], we should just support up to m.
    
    for (int i = n; i >= 2; i--) {
        vector<pair<int, ll>> updates;
        for (int u = i; u <= m; u += i) {
            int b = u - i;
            if (b < 0) continue; // Should not happen
            // Current max score from i+1 onwards, given b_{i+1} >= b_i = b
            ll current_suffix = query(1, 0, N_tree, b, N_tree);
            
            // v(i, u) calculation
            // optimization: u = k*i, so v(i, u) = 1 + v(i, k)
            int val_v = get_v(i, u);
            
            updates.push_back({b, current_suffix + val_v});
        }
        // Apply updates
        for (auto& p : updates) {
            update(1, 0, N_tree, p.first, p.second);
        }
    }

    cout << query(1, 0, N_tree, 0, N_tree) << nl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);
 
    int T = 1;
	cin >> T;
    while(T--) {
        solve();
    }
 
	return 0;
}
