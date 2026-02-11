class Solution {
    bool isPrime(int n) {
        if (n == 1) return false;
        for (int i=2; i*i<=n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> primes;
        for (int i=0; i<n; i++) {
            if (isPrime(nums[i])) primes.push_back(i);
        }
        return primes[primes.size()-1] - primes[0];
    }
};
