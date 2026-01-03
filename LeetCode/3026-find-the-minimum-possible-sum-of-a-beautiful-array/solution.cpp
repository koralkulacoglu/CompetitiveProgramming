int MOD = 1e9 + 7;

class Solution {
public:
    int minimumPossibleSum(int n, int target) {
        if (n <= target/2) return (n*(n+1)/2)%MOD;
        
        long long m = target/2;
        long long sum = m*(m+1)/2;
        long long nums = n-m;
        
        sum += nums*(2*target + nums - 1)/2;
        
        return sum%MOD;
    }
};

