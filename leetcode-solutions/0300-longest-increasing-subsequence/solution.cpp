class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int s = nums.size();
        int mx = 0;
        vector<int> dp(s, 1);
        for (int i=0; i<s; i++) {
            for (int j=0; j<i; j++) {
                if (nums[j] < nums[i] && dp[i]<dp[j]+1) {
                    dp[i] = dp[j]+1;
                }
            }
            mx = max(mx, dp[i]);
        }
        return mx;
    }
};
