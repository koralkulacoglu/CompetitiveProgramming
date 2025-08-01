class Solution {
public:
    const int MOD = 1e9 + 7;

    long long modpow(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    int stringCount(int n) {
        long long total = modpow(26, n);
    
        long long A = (modpow(25, n) + n * modpow(25, n - 1) % MOD) % MOD;
        long long B = modpow(25, n);
        long long C = modpow(25, n);
    
        long long AB = (modpow(24, n) + n * modpow(24, n - 1) % MOD) % MOD;
        long long AC = AB;
        long long BC = modpow(24, n);
    
        long long ABC = (modpow(23, n) + n * modpow(23, n - 1) % MOD) % MOD;
    
        long long bad = (A + B + C - AB - AC - BC + ABC) % MOD;
        if (bad < 0) bad += MOD;
    
        long long good = (total - bad + MOD) % MOD;
        return good;
    }
};
