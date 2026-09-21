class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(k, 0));
        dp[0][nums[0] % k] = 1;
        for (int i=1; i<n; i++) {
            int val = nums[i] % k;
            dp[i][val]++;
            for (int j=0; j<k; j++) {
                dp[i][(j * val) % k] += dp[i-1][j];
            }
        }

        vector<long long> res(k, 0);
        for (auto& i : dp) {
            for (int j=0; j<k; j++) res[j] += i[j];
        }

        return res;
    }
};
