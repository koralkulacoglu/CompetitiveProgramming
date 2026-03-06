class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int d=-500; d<=500; d++) {
            vector<int> dp(2001, 0);
            for (int num : nums) {
                num += 500;
                dp[num] = dp[num - d] + 1;
                ans = max(ans, dp[num]);
            }
        }
        return ans;
    }
};
