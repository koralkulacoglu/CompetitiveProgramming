class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > total) return 0;
        int m = 2*total + 1;
        vector<int> dp(m, 0);
        dp[total] = 1;
        for (int i=0; i<n; i++) {
            vector<int> newDp(m, 0);
            for (int j=0; j<m; j++) {
                if (j+nums[i] < m) newDp[j+nums[i]] += dp[j];
                if (j-nums[i] >= 0) newDp[j-nums[i]] += dp[j];
            }
            dp = newDp;
        }
        return dp[total+target];
    }
};
