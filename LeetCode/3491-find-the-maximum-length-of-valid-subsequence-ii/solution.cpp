class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for (int c = 0; c < k; ++c) {
            unordered_map<int, int> lastIdx;
            vector<int> dp(n, 1);

            for (int i=0; i<n; i++) {
                int val = nums[i] % k;
                int prevIdx = lastIdx[(c - val + k) % k];
                if (prevIdx) dp[i] = dp[prevIdx - 1] + 1;

                lastIdx[val] = i + 1;
                ans = max(ans, dp[i]);
            }
        }

        return ans;
    }
};
