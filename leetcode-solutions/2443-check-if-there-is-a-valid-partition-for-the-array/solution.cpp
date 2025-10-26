/*

idea: keep a frequency map and when you insert i, check if invalid, if so move left pointer until dp[left] = true. if that works dp[i] = true, else dp[i] = false

*/


class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();

        vector<bool> dp(n+1, false);
        dp[0] = true;

        for (int i=0; i<=n; i++) {
            if (!dp[i]) continue;
            if (i < n-1 && nums[i] == nums[i+1]) dp[i+2] = true;
            if (i < n-2 && nums[i] == nums[i+1] && nums[i] == nums[i+2]) dp[i+3] = true;
            if (i < n-2 && nums[i] == nums[i+1]-1 && nums[i+1] == nums[i+2]-1) dp[i+3] = true;
        }

        return dp[n];
    }
};
