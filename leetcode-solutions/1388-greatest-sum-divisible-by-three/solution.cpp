class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp = {0, (int)-1e9, (int)-1e9};
        for (int i=0; i<n; i++) {
            vector<int> temp = dp;
            for (int j=0; j<3; j++) {
                if (temp[j] == -1e9) continue;
                int currentSum = temp[j] + nums[i];
                int remainder = currentSum % 3;
                dp[remainder] = max(dp[remainder], currentSum);
            }
        }

        return dp[0];
    }
};
