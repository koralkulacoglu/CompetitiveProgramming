class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1e9); dp[0] = 0;
        for (int i=1; i<n; i++) {
            for (int j=0; j<i; j++) {
                if (abs(nums[i] - nums[j]) <= target) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return dp[n-1] > 0 ? dp[n-1] : -1;
    }
};
