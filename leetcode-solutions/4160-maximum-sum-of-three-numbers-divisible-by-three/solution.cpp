class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        vector<pair<int, int>> dp(3, {-1e9, -1e9}); // best 2 numbers
        vector<int> dp2(3, -1e9); // 2 numbers
        for (int i : nums) {
            if (i%3 == 0) ans = max(ans, i + dp2[0]);
            if (i%3 == 1) ans = max(ans, i + dp2[2]);
            if (i%3 == 2) ans = max(ans, i + dp2[1]);

            if (dp[i%3].first <= i) {
                dp[i%3].second = dp[i%3].first;
                dp[i%3].first = i;
            }
            else if (dp[i%3].second <= i) {
                dp[i%3].second = i;
            }
            
            dp2[0] = max(dp2[0], dp[0].first + dp[0].second);
            dp2[0] = max(dp2[0], dp[1].first + dp[2].first);
            
            dp2[1] = max(dp2[1], dp[0].first + dp[1].first);
            dp2[1] = max(dp2[1], dp[2].first + dp[2].second);
            
            dp2[2] = max(dp2[2], dp[0].first + dp[2].first);
            dp2[2] = max(dp2[2], dp[1].first + dp[1].second);
        }

        return ans;
    }
};
