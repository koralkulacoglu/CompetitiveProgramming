class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        unordered_map<int, int> dp;
        for (int num : nums) {
            dp[num+1] = max(dp[num+1], dp[num] + 1);
            dp[num] = max(dp[num], dp[num-1] + 1);
            ans = max(ans, dp[num]);
            ans = max(ans, dp[num+1]);
        }
        return ans;
    }
};

