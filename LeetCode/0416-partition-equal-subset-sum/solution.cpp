class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int m = accumulate(nums.begin(), nums.end(), 0);
        if (m%2) return false;
        vector<bool> dp(m/2+1, false);
        dp[0] = true;
        if (nums[0] <= m/2) dp[nums[0]] = true;
        for (int i=1; i<n; i++) {
            vector<bool> newDp = dp;
            newDp[nums[i]] = true;
            for (int j=0; j<=m/2; j++) {
                if (!dp[j] || nums[i] + j > m/2) continue;
                newDp[nums[i] + j] = true;
            }
            dp = newDp;
        }
        return dp[m/2];
    }
};
