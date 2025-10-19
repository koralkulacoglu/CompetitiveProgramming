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

typedef pair<int,int> pi;
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

#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define F0R(i,a) for (int i=0; i<(a); ++i)
#define FORd(i,a,b) for (int i=(a)-1; i>=(b); --i)
#define F0Rd(i,a) for (int i=(a)-1; i>=0; --i)
#define trav(a,x) for (auto& a : x)
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
#define ins insert
#define lbound(a,v) (int)(lower_bound(all(a), (v)) - (a).begin())
#define ubound(a,v) (int)(upper_bound(all(a), (v)) - (a).begin())
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)/gcd((a),(b))*(b))

template<class T> bool ckmin(T& a, const T& b) { return b < a ? (a = b, true) : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? (a = b, true) : false; }

void __print(int x){ cerr<<x; }
void __print(long x){ cerr<<x; }
void __print(long long x){ cerr<<x; }
void __print(unsigned x){ cerr<<x; }
void __print(unsigned long x){ cerr<<x; }
void __print(unsigned long long x){ cerr<<x; }
void __print(float x){ cerr<<x; }
void __print(double x){ cerr<<x; }
void __print(long double x){ cerr<<x; }
void __print(char x){ cerr<<'\''<<x<<'\''; }
void __print(const char* x){ cerr<<'\"'<<x<<'\"'; }
void __print(const string& x){ cerr<<'\"'<<x<<'\"'; }
void __print(bool x){ cerr<<(x?"true":"false"); }

template<typename T, typename V> void __print(const pair<T,V>& x);
template<typename T> void __print(const T& x){ int f=0; cerr<<'{'; for(const auto& i:x) cerr<<(f++?", ":""), __print(i); cerr<<'}'; }
template<typename T, typename V> void __print(const pair<T,V>& x){ cerr<<'{'; __print(x.first); cerr<<", "; __print(x.second); cerr<<'}'; }
void _print(){ cerr<<"]\n"; }
template<typename T, typename... V> void _print(T t, V... v){ __print(t); if(sizeof...(v)) cerr<<", "; _print(v...); }

#ifdef DEBUG
#define dbg(x...) cerr<<__func__<<":"<<__LINE__<<" ["<<#x<<"] = ["; _print(x);
#else
#define dbg(x...)
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct custom_hash {
    size_t operator()(uint64_t x) const {
        x ^= (uint64_t)rng();
        return x ^ (x >> 16);
    }
};

const int MOD = 1000000007;
const char nl = '\n';

using u64 = unsigned long long;

// -------- mod helpers --------
inline u64 addm(u64 a, u64 b){ a+=b; return (a>= (u64)MOD ? a-(u64)MOD : a); }
inline u64 mulm(u64 a, u64 b){ return (u64)((__int128)a * b % MOD); }
u64 pwr(u64 a, u64 e){ u64 r=1; while(e){ if(e&1) r=mulm(r,a); a=mulm(a,a); e>>=1; } return r; }
inline u64 invm(u64 a){ return pwr(a, MOD-2); }

// -------- Miller–Rabin + Pollard–Rho (64-bit safe) --------
inline u64 mul64(u64 a, u64 b, u64 m){ return (u64)((__int128)a * b % m); }
u64 pow64(u64 a, u64 e, u64 m){ u64 r=1; while(e){ if(e&1) r=mul64(r,a,m); a=mul64(a,a,m); e>>=1; } return r; }
bool isPrime(u64 n){
    if(n < 2) return false;
    static const u64 small[] = {2ULL,3ULL,5ULL,7ULL,11ULL,13ULL,17ULL,19ULL,23ULL,29ULL,31ULL,37ULL};
    for(u64 p: small){ if(n % p == 0) return n == p; }
    u64 d = n - 1, s = 0;
    while((d & 1) == 0){ d >>= 1; ++s; }
    auto chk = [&](u64 a)->bool{
        if(a % n == 0) return true;
        u64 x = pow64(a, d, n);
        if(x == 1 || x == n-1) return true;
        for(u64 i=1;i<s;i++){ x = mul64(x,x,n); if(x == n-1) return true; }
        return false;
    };
    // Deterministic bases for 64-bit
    for(u64 a: {2ULL,325ULL,9375ULL,28178ULL,450775ULL,9780504ULL,1795265022ULL})
        if(!chk(a)) return false;
    return true;
}
u64 rho(u64 n){
    if((n & 1ULL) == 0ULL) return 2ULL;
    uniform_int_distribution<u64> dist(2ULL, n-2ULL);
    while(true){
        u64 c = dist(rng), x = dist(rng), y = x, d = 1;
        auto f = [&](u64 v){ return (mul64(v,v,n) + c) % n; };
        while(d == 1){
            x = f(x);
            y = f(f(y));
            u64 diff = x > y ? x - y : y - x;
            d = std::gcd(diff, n);
        }
        if(d != n) return d;
    }
}
void factor_rec(u64 n, vector<u64>& out){
    if(n == 1) return;
    if(isPrime(n)){ out.pb(n); return; }
    u64 d = rho(n);
    factor_rec(d, out);
    factor_rec(n/d, out);
}

// -------- C(N-1+t, t) row for t=0..E, N can be huge --------
vector<u64> binom_row_rising(u64 N_raw, int E){
    vector<u64> C(E+1); C[0] = 1;
    vector<u64> inv(E+1);
    for(int i=1;i<=E;i++) inv[i] = invm((u64)i);
    u64 Nm = N_raw % MOD;
    for(int t=1; t<=E; ++t){
        u64 term = (Nm + (u64)(t-1)) % MOD;    // N + t - 1
        C[t] = mulm(C[t-1], term);             // multiply numerator
        C[t] = mulm(C[t],    inv[t]);          // divide by t (cumulative / t!)
    }
    return C; // C[t] = C(N-1+t, t)
}

void solve(){
    int T; 
    cin >> T;
    FOR(tc, 1, T+1){
        u64 N, A, B; 
        cin >> N >> A >> B;

        // factor B
        vector<u64> fac; fac.reserve(16);
        factor_rec(B, fac);
        sort(all(fac));
        vector<u64> primes; vector<int> exps;
        for(size_t i=0; i<fac.size(); ){
            size_t j=i; while(j<fac.size() && fac[j]==fac[i]) ++j;
            primes.pb(fac[i]); exps.pb((int)(j-i));
            i=j;
        }

        u64 ans = 0;

        if(A >= B){
            // F_{2N}(B) = prod_p C(2N-1+e, e)
            u64 res = 1;
            for(int e: exps){
                auto C = binom_row_rising(2ULL * N, e);
                res = mulm(res, C[e]);
            }
            ans = res;
        }else{
            u64 minp = primes.empty() ? (u64)-1 : primes[0];
            if(A < minp){
                // only D = 1 allowed -> F_N(B) = prod_p C(N-1+e, e)
                u64 res = 1;
                for(int e: exps){
                    auto C = binom_row_rising(N, e);
                    res = mulm(res, C[e]);
                }
                ans = res;
            }else{
                // general case: DFS over exponents with product D <= A
                int m = (int)primes.size();
                vector<vector<u64>> C1(m), C2(m); // C1[i][k]=C(N-1+k,k), C2[i][k]=C(N-1+e-k,e-k)
                for(int i=0;i<m;i++){
                    int e = exps[i];
                    C1[i] = binom_row_rising(N, e);
                    C2[i].assign(e+1, 0);
                    for(int k=0;k<=e;k++) C2[i][k] = C1[i][e - k];
                }

                u64 total = 0;
                function<void(int,u64,u64)> dfs = [&](int idx, u64 D, u64 ways){
                    if(idx == m){
                        total = addm(total, ways);
                        return;
                    }
                    u64 p = primes[idx]; int e = exps[idx];
                    u64 Dcur = D;
                    for(int k=0;k<=e;k++){
                        if(Dcur <= A){
                            u64 mult = mulm(C1[idx][k], C2[idx][k]);
                            dfs(idx+1, Dcur, mulm(ways, mult));
                        }else break;
                        if(k < e){
                            if(Dcur > A / p) break; // avoid overflow and prune
                            Dcur *= p;
                        }
                    }
                };
                dfs(0, 1, 1);
                ans = total;
            }
        }

        cout << "Case #" << tc << ": " << ans << nl;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
    return 0;
}

