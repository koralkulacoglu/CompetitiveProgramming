class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> psa(n+1, 0);
        for (int i=1; i<n+1; i++) psa[i] = psa[i-1] + nums[i-1];

        vector<long long> dp(n, -1e18);
        dp[k-1] = accumulate(nums.begin(), nums.begin()+k, 0LL);
        for (int i=k; i<n; i++) {
            dp[i] = max(dp[i-k] + psa[i+1] - psa[i+1-k], psa[i+1] - psa[i+1-k]);
        }

        return *max_element(dp.begin(), dp.end());
    }
};
