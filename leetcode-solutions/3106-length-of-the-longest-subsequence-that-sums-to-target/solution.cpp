class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(1001, 0)); // stores max number of values to sum to index i
        
        dp[0][nums[0]] = 1;
        for (int i=1; i<n; i++) {
            for (int j=0; j<=1000; j++) dp[i][j] = dp[i-1][j];
            dp[i][nums[i]] = max(dp[i][nums[i]], 1);
            
            for (int j=0; j<=1000; j++) {
                if (j + nums[i] > target) break;
                
                if (dp[i-1][j]) dp[i][j + nums[i]] = max(dp[i][j + nums[i]], dp[i-1][j] + 1);
            }
        }
        
        /*
        for (auto i : dp) {
            for (int j : i) {
                cout << j << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
        */

        return dp[n-1][target]>0?dp[n-1][target]:-1;
    }
};
