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

typedef long long ll_alias;
using my_int = long long;


const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;

int CASE_NUM = 1;

void solve() {
    int N;
    ll M;
    if (!(cin >> N >> M)) return;

    vll A(N);
    F0R(i, N) cin >> A[i];

    ll Amin = *min_element(all(A));
    ll Bmax_ll = (M + Amin - 1) / Amin;   // upper bound on bricks

    // If Bmax is huge, fall back to a simple greedy (not guaranteed optimal for
    // the very worst theoretical cases, but fast and safe for large bounds).
    const ll LIMIT = 2000000LL;
    if (Bmax_ll > LIMIT) {
        ll maxA = 0;
        int idx = 0;
        F0R(i, N) if (A[i] > maxA) { maxA = A[i]; idx = i; }
        ll h = (M + maxA - 1) / maxA;

        vll x(N, 0);
        F0R(i, idx + 1) x[i] = h;
        ll bricks = h * (idx + 1);

        cout << "Case #" << CASE_NUM++ << ": " << bricks << nl;
        F0R(i, N) {
            if (i) cout << ' ';
            cout << x[i];
        }
        cout << nl;
        return;
    }

    int Bmax = (int)Bmax_ll;

    // Prefix sums P_k
    vll P(N);
    ll s = 0;
    F0R(i, N) {
        s += A[i];
        P[i] = s;
    }

    const ll NEG = (ll)-4e18;
    vector<ll> dp(Bmax + 1, NEG);
    vi prev_b(Bmax + 1, -1);
    vi choice(Bmax + 1, -1);
    dp[0] = 0;

    // Unbounded knapsack on "layers": cost = k bricks, value = P[k-1] amazingness
    FOR(k, 1, N + 1) {
        int cost = k;
        ll value = P[k - 1];
        FOR(b, cost, Bmax + 1) {
            if (dp[b - cost] == NEG) continue;
            ll cand = dp[b - cost] + value;
            if (cand > dp[b]) {
                dp[b] = cand;
                prev_b[b] = b - cost;
                choice[b] = k;
            }
        }
    }

    int bestB = -1;
    F0R(b, Bmax + 1) {
        if (dp[b] >= M) {
            bestB = b;
            break;
        }
    }

    // Reconstruct counts of layers y_k
    vll y(N + 1, 0);
    int b = bestB;
    while (b > 0) {
        int k = choice[b];
        if (k == -1) break;
        y[k]++;
        b = prev_b[b];
    }

    // Convert y_k to heights x_i:
    // x_i = sum_{k=i..N} y_k
    vll x(N + 2, 0);
    for (int i = N; i >= 1; --i) {
        x[i] = x[i + 1] + y[i];
    }

    cout << "Case #" << CASE_NUM++ << ": " << bestB << nl;
    FOR(i, 1, N + 1) {
        if (i > 1) cout << ' ';
        cout << x[i];
    }
    cout << nl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

