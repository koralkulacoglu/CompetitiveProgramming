class Solution {
public:
    int minimizeXor(int num1, int num2) {
        long long bits = __builtin_popcount(num2);
        long long ans = 0;
        for (long long i=32; i>=0; i--) {
            if (!bits) break;
            if (num1 & (1LL << i)) {
                ans |= 1LL << i;
                bits--;
            }
        }
        for (long long i=0; i<32; i++) {
            if (!bits) break;
            if (!(num1 & (1LL << i))) {
                ans |= 1LL << i;
                bits--;
            }
        }
        return ans;
    }
};
