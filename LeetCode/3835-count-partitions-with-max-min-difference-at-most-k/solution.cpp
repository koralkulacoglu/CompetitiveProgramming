class Solution {
    int MOD = 1e9+7;
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        multiset<int> window;
        vector<int> dp(n+1, 0); dp[0] = 1;
        vector<int> dpPsa(n+2, 0); dpPsa[1] = 1;
        for (int r=0; r<n; r++) {
            window.insert(nums[r]);
            while (*window.rbegin() - *window.begin() > k) {
                auto it = window.find(nums[l]);
                window.erase(it);
                l++;
            }
            dp[r+1] = (dpPsa[r + 1] - dpPsa[l] + MOD) % MOD;
            dpPsa[r+2] = (dpPsa[r+1] + dp[r+1]) % MOD;
        }
        return dp[n];
    }
};
