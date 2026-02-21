class Solution {
    bool isPrimeBits(int n) {
        int bits = __builtin_popcount(n);
        if (bits == 1) return false;
        for (int i=2; i*i<=bits; i++) {
            if (bits % i == 0) return false;
        }
        return true;
    }
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int i=left; i<=right; i++) ans += isPrimeBits(i);
        return ans;
    }
};
