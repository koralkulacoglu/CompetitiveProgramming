class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string, bool> seen;
        for (string i : wordDict) seen[i] = true;
        int n = s.size();
        vector<bool> dp(n, 0);
        for (int i=0; i<n; i++) {
            if (i != 0 && dp[i-1] != 1) continue;
            string cur;
            for (int j=i; j<n; j++) {
                cur += s[j];
                if (seen[cur]) dp[j] = true;
            }
        }
        return dp[n-1];
    }
};
