class Solution {
public:
    int concatenatedBinary(int n) {
        long long MOD = 1e9+7;
        long long ans = 1;
        for (long long i=2; i<=n; i++) {
            long long bits = i > 0 ? static_cast<int>(log2(i)) + 1 : 1;
            ans = (ans << bits) % MOD + i; 
        }

        return ans;
    }
};
