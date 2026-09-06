class Solution {
    static const int MOD = 1e9;
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<int> dp(m+1, 0); // dp[i] = # subseqs for prefix of size i
        dp[0] = 1;
        for (char sc : s) {
            for (int i=m; i>0; i--) {
                char tc = t[i-1];
                if (sc == tc) dp[i] += dp[i-1];
                dp[i] %= MOD;
            }
        }

        return dp[m];
    }
};
