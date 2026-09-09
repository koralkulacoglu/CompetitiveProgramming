class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0, start = 1000;
        while (start <= n) {
            ans += n - start + 1;
            start *= 1000;
        }
        return ans;
    }
};
