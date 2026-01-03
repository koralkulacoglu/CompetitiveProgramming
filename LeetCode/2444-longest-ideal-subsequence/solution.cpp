class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(26, 0));
        dp[0][s[0]-'a'] = 1;
        for (int i=1; i<n; i++) {
            char cur = s[i]-'a';
            for (int j=0; j<26; j++) dp[i][j] = dp[i-1][j];
            for (int j=max(0, cur-k); j<min(26, cur+k+1); j++) {
                dp[i][cur] = max(dp[i][cur], dp[i-1][j]+1);
            }
        }
        return *max_element(dp[n-1].begin(), dp[n-1].end());
    }
};
