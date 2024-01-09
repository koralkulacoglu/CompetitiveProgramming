class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        // do dp starting at each i
        int ans = 0;
        for (int i=0; i<n; i++) {
            vector<int> dp(n-1, 0);
            dp[0] = nums[i];
            dp[1] = max(nums[i], nums[(i+1)%n]);
            for (int j=2; j<n-1; j++) {
                dp[j] = max(dp[j-1], dp[j-2] + nums[(i+j)%n]);
            }
            ans = max(ans, dp[n-2]);
        }
        return ans;
    }
};
