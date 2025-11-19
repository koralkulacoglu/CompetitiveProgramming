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

typedef long long ll_alias;
using my_int = long long;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct custom_hash {
    size_t operator()(uint64_t x) const {
        x ^= rng();
        return x ^ (x >> 16);
    }
};
 
const int MOD = 998244353;
const char nl = '\n';
const int MX = 100001; 

inline int addmod(int a, int b) {
    int s = a + b;
    if (s >= MOD) s -= MOD;
    return s;
}
inline int mulmod(long long a, long long b) {
    return int((a * b) % MOD);
}

string decString(const string &s) {
    string t = s;
    int n = sz(t);
    int i = n - 1;
    while (i >= 0 && t[i] == '0') {
        t[i] = '9';
        --i;
    }
    if (i >= 0) t[i]--;
    int pos = 0;
    while (pos + 1 < sz(t) && t[pos] == '0') ++pos;
    return t.substr(pos);
}

int modFromString(const string &s) {
    long long val = 0;
    for (char c : s) {
        val = (val * 10 + (c - '0')) % MOD;
    }
    return (int)val;
}

inline uint32_t rotateK(uint32_t s, int dr, int K) {
    dr %= K;
    if (dr == 0) return s;
    uint32_t mask = (1u << K) - 1u;
    return (uint32_t)(((s << dr) & mask) | (s >> (K - dr)));
}

vector<int> strongCount[26];
bool prepared[26];

void prepareK(int K) {
    if (prepared[K]) return;
    prepared[K] = true;
    int maxLen = K - 1;
    strongCount[K].assign(maxLen + 1, 0);

    vi digits;
    FOR(d, 1, 10) if (d % K != 0) digits.pb(d);

    vi cntRes(K, 0);
    trav(d, digits) {
        int r = d % K;
        cntRes[r]++;
    }
    vi residues;
    FOR(r, 1, K) if (cntRes[r] > 0) residues.pb(r);

    unordered_map<uint32_t,int> dp_cur, dp_next;
    dp_cur.reserve(1u << min(K, 18));
    dp_next.reserve(1u << min(K, 18));
    dp_cur.max_load_factor(0.7f);
    dp_next.max_load_factor(0.7f);

    dp_cur.clear();
    trav(r, residues) {
        uint32_t state = (1u << r);
        int ways = cntRes[r];
        dp_cur[state] = addmod(dp_cur[state], ways);
    }
    int total = 0;
    for (auto &p : dp_cur) total = addmod(total, p.second);
    strongCount[K][1] = total;

    FOR(len, 2, maxLen + 1) {
        dp_next.clear();
        for (auto &pr : dp_cur) {
            uint32_t state = pr.first;
            int ways = pr.second;
            if (!ways) continue;
            trav(r, residues) {
                uint32_t ns = rotateK(state, r, K) | (1u << r);
                if (ns & 1u) continue;
                int add = mulmod(ways, cntRes[r]);
                auto it = dp_next.find(ns);
                if (it == dp_next.end()) dp_next.emplace(ns, add);
                else it->second = addmod(it->second, add);
            }
        }
        dp_cur.swap(dp_next);
        total = 0;
        for (auto &p : dp_cur) total = addmod(total, p.second);
        strongCount[K][len] = total;
    }
}

int countStrongSameLenLE(const string &s, int K) {
    int m = sz(s);
    if (m >= K) return 0;

    unordered_map<uint32_t,int> tight, loose, ntight, nloose;
    tight.reserve(1u << min(K, 18));
    loose.reserve(1u << min(K, 18));
    ntight.reserve(1u << min(K, 18));
    nloose.reserve(1u << min(K, 18));
    tight.max_load_factor(0.7f);
    loose.max_load_factor(0.7f);
    ntight.max_load_factor(0.7f);
    nloose.max_load_factor(0.7f);

    tight.clear();
    loose.clear();
    tight[0] = 1;

    F0R(pos, m) {
        ntight.clear();
        nloose.clear();
        int limT = s[pos] - '0';

        for (auto &pr : tight) {
            uint32_t state = pr.first;
            int ways = pr.second;
            if (!ways) continue;
            FOR(d, (pos == 0 ? 1 : 0), limT + 1) {
                if (d % K == 0) continue;
                int r = d % K;
                uint32_t ns = rotateK(state, r, K) | (1u << r);
                if (ns & 1u) continue;
                bool nt = (d == limT);
                if (nt) {
                    auto it = ntight.find(ns);
                    if (it == ntight.end()) ntight.emplace(ns, ways);
                    else it->second = addmod(it->second, ways);
                } else {
                    auto it = nloose.find(ns);
                    if (it == nloose.end()) nloose.emplace(ns, ways);
                    else it->second = addmod(it->second, ways);
                }
            }
        }

        for (auto &pr : loose) {
            uint32_t state = pr.first;
            int ways = pr.second;
            if (!ways) continue;
            FOR(d, (pos == 0 ? 1 : 0), 10) {
                if (d % K == 0) continue;
                int r = d % K;
                uint32_t ns = rotateK(state, r, K) | (1u << r);
                if (ns & 1u) continue;
                auto it = nloose.find(ns);
                if (it == nloose.end()) nloose.emplace(ns, ways);
                else it->second = addmod(it->second, ways);
            }
        }

        tight.swap(ntight);
        loose.swap(nloose);
    }

    int ans = 0;
    for (auto &p : tight) ans = addmod(ans, p.second);
    for (auto &p : loose) ans = addmod(ans, p.second);
    return ans;
}

int countStrongUpTo(const string &s, int K) {
    int n = sz(s);
    if (n == 0) return 0;
    int maxLen = min(n, K - 1);
    if (maxLen <= 0) return 0;

    prepareK(K);

    int res = 0;
    FOR(len, 1, maxLen) {
        res = addmod(res, strongCount[K][len]);
    }

    if (maxLen < n) {
        return res;
    } else {
        int extra = countStrongSameLenLE(s, K);
        res = addmod(res, extra);
        return res;
    }
}

void solve() {
    string l, r; 
    cin >> l >> r;
    int k; 
    cin >> k;

    auto weakUpTo = [&](const string &N) -> int {
        if (N == "0") return 0;
        int total = modFromString(N);
        int strong = countStrongUpTo(N, k);
        int weak = total - strong;
        if (weak < 0) weak += MOD;
        return weak;
    };

    int ansR = weakUpTo(r);
    int ansL1 = 0;
    if (l != "1") {
        string lm1 = decString(l);
        ansL1 = weakUpTo(lm1);
    }
    int ans = ansR - ansL1;
    if (ans < 0) ans += MOD;

    cout << ans << nl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);
 
    int T = 1;
    cin >> T;
    FOR(i, 1, T+1) {
        cout << "Case #" << i << ": ";
        solve();
    }
 
    return 0;
}

