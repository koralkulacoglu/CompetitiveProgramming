/*
ID: Koral Kulacoglu
TASK: test
LANG: C++                 
*/

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef long double lld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;
 
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<ld> vld;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<cd> vcd;

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i, a, b) for (int i=(a)-1; i >= b; i--)
#define F0Rd(i, a) for (int i=(a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
#define ins insert
#define lbound(a, v) lower_bound(all(a), v)-a.begin()
#define ubound(a, v) upper_bound(all(a), v)-a.begin()
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a*b)/gcd(a, b)
 
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x);
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifdef DEBUG
#define dbg(x...) cerr <<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << endl;
#else
#define dbg(x...)
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct custom_hash {
    size_t operator()(uint64_t x) const {
        x ^= rng();
        return x ^ (x >> 16);
    }
};
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; 

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

class SparseSegtree {
  private:
    struct Node {
        int freq = 0; // # of 1s
        int val = 0; // hash
        bool lazy = false;
        Node *left = nullptr;
        Node *right = nullptr;
    };

    Node *root = new Node;
    const int n;

    int get_freq(Node* node) { return node ? node->freq : 0; }
    int get_val(Node* node) { return node ? node->val : 0; }

    void push_up(Node *cur, int len_l, int len_r) {
        int f_l = get_freq(cur->left);
        int v_l = get_val(cur->left);
        int f_r = get_freq(cur->right);
        int v_r = get_val(cur->right);

        cur->freq = f_l + f_r;
        cur->val = (1LL * v_l * binpow(2, len_r) + v_r) % MOD;
    }

    void apply_flip(Node *cur, int len) {
        if (!cur) return;
        cur->lazy = !cur->lazy;
        cur->freq = len - cur->freq;

        ll all_ones = (binpow(2, len) - 1 + MOD) % MOD;
        cur->val = (all_ones - cur->val + MOD) % MOD;
    }

    void push_down(Node *cur, int l, int r) {
        if (!cur->lazy) return;

        if (cur->left == nullptr) cur->left = new Node;
        if (cur->right == nullptr) cur->right = new Node;

        int m = (l + r) / 2;
        apply_flip(cur->left, m - l + 1);
        apply_flip(cur->right, r - m);

        cur->lazy = false;
    }

    void range_flip(Node *cur, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return;
        if (ql <= l && r <= qr) {
            apply_flip(cur, r - l + 1);
            return;
        }
        push_down(cur, l, r);
        int m = (l + r) / 2;

        if (!cur->left) cur->left = new Node;
        if (!cur->right) cur->right = new Node;

        range_flip(cur->left, l, m, ql, qr);
        range_flip(cur->right, m + 1, r, ql, qr);
        push_up(cur, m - l + 1, r - m);
    }

    pair<int, int> query(Node *cur, int l, int r, int ql, int qr) {
        if (!cur || qr < l || ql > r) return {0, 0};
        if (ql <= l && r <= qr) {
            return {cur->freq, cur->val};
        }
        push_down(cur, l, r);
        int m = (l + r) / 2;

        pair<int, int> res_l = query(cur->left, l, m, ql, qr);
        pair<int, int> res_r = query(cur->right, m + 1, r, ql, qr);

        int overlap_r = max(0, min(r, qr) - max(m + 1, ql) + 1);

        int combined_freq = res_l.first + res_r.first;
        int combined_val = (1LL * res_l.second * binpow(2, overlap_r) + res_r.second) % MOD;

        return {combined_freq, combined_val};
    }

	int find_kth_zero_in_range(Node* cur, int l, int r, int ql, int qr, int& k) {
		if (!cur || qr < l || ql > r) {
			int overlap = max(0, min(r, qr) - max(l, ql) + 1);
			if (overlap > 0) {
				if (k <= overlap) {
					return max(l, ql) + k - 1;
				}
				k -= overlap;
			}
			return -1;
		}

		if (ql <= l && r <= qr) {
			int zeros_in_node = (r - l + 1) - cur->freq;
			if (k > zeros_in_node) {
				k -= zeros_in_node;
				return -1;
			}
		}

		if (l == r) {
			 if (cur->freq == 0) {
				 if (k == 1) return l;
				 k--;
			 }
			 return -1;
		}

		push_down(cur, l, r);
		int m = (l + r) / 2;

		int res = find_kth_zero_in_range(cur->left, l, m, ql, qr, k);
		if (res != -1) return res;

		return find_kth_zero_in_range(cur->right, m + 1, r, ql, qr, k);
	}

  public:
    SparseSegtree(int n) : n(n) {}

    void range_flip(int ql, int qr) {
        range_flip(root, 0, n - 1, ql, qr);
    }

    pair<int, int> query_data(int ql, int qr) {
        return query(root, 0, n - 1, ql, qr);
    }

    int get_split_index(int ql, int qr, int k) {
        int k_copy = k;
        return find_kth_zero_in_range(root, 0, n - 1, ql, qr, k_copy);
    }
};
 
void solve() {
	int n, m, q; cin >> n >> m >> q;

	SparseSegtree st(n);
	FOR (i, 0, m) {
		int l, r; cin >> l >> r; l--; r--;
		st.range_flip(l, r);
	}

	FOR (i, 0, q) {
		int l, r, k; cin >> l >> r >> k; l--; r--;

		int len = r - l + 1;
		pi range_info = st.query_data(l, r);

		int ones = range_info.fir;
		int zeros = len - ones;
		int toDelete = len - k;

		if (toDelete >= zeros) {
			ll ans = (binpow(2, k) - 1 + MOD) % MOD;
			cout << ans << nl;
		}
		else {
			int splitIdx = st.get_split_index(l, r, toDelete+1);

			pi left = st.query_data(l, splitIdx-1);
			int leftOnes = left.fir;
			ll leftVal = (binpow(2, leftOnes) - 1 + MOD) % MOD;

			pi right = st.query_data(splitIdx, r);
			ll rightVal = right.sec;
			ll rightLen = r - splitIdx + 1;

			ll ans = (leftVal * binpow(2, rightLen) + rightVal) % MOD;
            cout << ans << nl;
		}
	}
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);
 
    int T = 1;
//    cin >> T;
    while(T--) {
        solve();
    }
 
	return 0;
}

