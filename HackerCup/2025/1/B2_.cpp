#include <bits/stdc++.h>
using namespace std;

using u64 = unsigned long long;
const u64 MOD = 1000000007ULL;

// ---------- mod helpers ----------
inline u64 addm(u64 a,u64 b){ a+=b; return a>=MOD?a-MOD:a; }
inline u64 mulm(u64 a,u64 b){ return (u64)((__int128)a*b%MOD); }
u64 pwr(u64 a,u64 e){ u64 r=1; for(;e;e>>=1,a=mulm(a,a)) if(e&1) r=mulm(r,a); return r; }
u64 inv(u64 a){ return pwr(a, MOD-2); }

// ---------- Miller–Rabin + Pollard–Rho ----------
inline u64 mul64(u64 a,u64 b,u64 m){ return (u64)((__int128)a*b%m); }
u64 pow64(u64 a,u64 e,u64 m){ u64 r=1; while(e){ if(e&1) r=mul64(r,a,m); a=mul64(a,a,m); e>>=1; } return r; }
bool isPrime(u64 n){
  if(n<2) return false;
  for(u64 p: {2ULL,3ULL,5ULL,7ULL,11ULL,13ULL,17ULL,19ULL,23ULL,29ULL,31ULL,37ULL}){ if(n%p==0) return n==p; }
  u64 d=n-1,s=0; while((d&1)==0){ d>>=1; ++s; }
  auto chk=[&](u64 a){ if(a%n==0) return true; u64 x=pow64(a,d,n); if(x==1||x==n-1) return true;
    for(u64 i=1;i<s;i++){ x=mul64(x,x,n); if(x==n-1) return true; } return false; };
  for(u64 a: {2ULL,325ULL,9375ULL,28178ULL,450775ULL,9780504ULL,1795265022ULL}) if(!chk(a)) return false;
  return true;
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
u64 rho(u64 n){
  if((n&1)==0) return 2;
  uniform_int_distribution<u64> dist(2,n-2);
  while(true){
    u64 c=dist(rng), x=dist(rng), y=x, d=1;
    auto f=[&](u64 v){ return (mul64(v,v,n)+c)%n; };
    while(d==1){ x=f(x); y=f(f(y)); u64 diff = x>y?x-y:y-x; d=gcd(diff,n); }
    if(d!=n) return d;
  }
}
void factor(u64 n, vector<u64>& out){
  if(n==1) return;
  if(isPrime(n)){ out.push_back(n); return; }
  u64 d=rho(n);
  factor(d,out); factor(n/d,out);
}

// ---------- C(N-1+t, t) for t=0..E with huge N ----------
vector<u64> rowC(u64 N_raw, int E){
    vector<u64> C(E+1); 
    C[0] = 1;
    u64 Nm = N_raw % MOD;

    // precompute inv(1..E) once (optional but faster)
    vector<u64> inv(E+1);
    for(int i=1;i<=E;i++) inv[i] = pwr(i, MOD-2);

    for(int t=1; t<=E; ++t){
        u64 term = (Nm + (u64)(t-1)) % MOD;     // N + t - 1
        C[t] = mulm(C[t-1], term);              // multiply by (N + t - 1)
        C[t] = mulm(C[t],    inv[t]);           // divide by t  (so cumulatively / t!)
    }
    return C;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T; 
  if(!(cin>>T)) return 0;
  for(int tc=1; tc<=T; ++tc){
    u64 N, A, B; cin >> N >> A >> B;

    // factor B
    vector<u64> fac; factor(B, fac);
    sort(fac.begin(), fac.end());
    vector<u64> primes; vector<int> exps;
    for(size_t i=0;i<fac.size();){
      size_t j=i; while(j<fac.size() && fac[j]==fac[i]) ++j;
      primes.push_back(fac[i]); exps.push_back((int)(j-i)); i=j;
    }

    u64 ans=0;

    if(A >= B){
      // F_{2N}(B) = prod_p C(2N-1+e, e)
      u64 res=1;
      for(int e: exps){
        auto C = rowC(2*N, e);      // pass raw 2N
        res = mulm(res, C[e]);
      }
      ans = res;
    }else{
      u64 minp = primes.empty()? (u64)-1 : primes[0];
      if(A < minp){
        // only D=1 allowed => F_N(B)
        u64 res=1;
        for(int e: exps){
          auto C = rowC(N, e);      // pass raw N
          res = mulm(res, C[e]);
        }
        ans = res;
      }else{
        // general case: DFS on exponents with D <= A
        int m = (int)primes.size();
        vector<vector<u64>> C1(m), C2(m);
        for(int i=0;i<m;i++){
          int e=exps[i];
          C1[i] = rowC(N, e);       // C(N-1+k, k)
          C2[i].resize(e+1);
          for(int k=0;k<=e;k++) C2[i][k] = C1[i][e-k]; // C(N-1+(e-k), e-k)
        }
        u64 total=0;
        function<void(int,u64,u64)> dfs = [&](int idx, u64 D, u64 ways){
          if(idx==m){ total = addm(total, ways); return; }
          u64 p=primes[idx]; int e=exps[idx];
          u64 Dcur=D;
          for(int k=0;k<=e;k++){
            if(Dcur <= A){
              u64 mult = mulm(C1[idx][k], C2[idx][k]);
              dfs(idx+1, Dcur, mulm(ways, mult));
            }else break;
            if(k<e){
              if(Dcur > A / p) break; // safe multiply
              Dcur *= p;
            }
          }
        };
        dfs(0, 1, 1);
        ans = total;
      }
    }

    cout << "Case #" << tc << ": " << ans << "\n";
  }
  return 0;
}

