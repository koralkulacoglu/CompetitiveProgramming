class Solution {
public:
    int deleteAndEarn(vector<int>& vals) {
        unordered_map<int, int> freq;
        for (int &i : vals) {
            freq[i]++;
        }
        int n=2e4+1;
        vector<int> dp(n, 0);
        dp[0] = 0;
        dp[1] = freq[1];
        for (int i=2; i<n; i++) {
            dp[i] = max(dp[i-1], dp[i-2]+i*freq[i]);
        }
        return dp[n-1];
    }
};
