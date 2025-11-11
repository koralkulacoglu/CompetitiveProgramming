class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int s = strs.size();
        vector<vector<int>> sizes(s, vector<int>(2, 0));
        for (int i=0; i<s; i++) {
            for (char c: strs[i]) sizes[i][c-'0']++;
        }

        vector<vector<int>> dp(m+1, vector<int>(n+1, -1e9));

        int ans = 0;
        dp[0][0] = 0;
        for (int i=0; i<s; i++) {
            for (int j=m; j>=0; j--) {
                for (int k=n; k>=0; k--) {
                    if (j+sizes[i][0] > m || k+sizes[i][1] > n) continue;
                    dp[j+sizes[i][0]][k+sizes[i][1]] = max(dp[j+sizes[i][0]][k+sizes[i][1]], dp[j][k] + 1);
                    ans = max(ans, dp[j+sizes[i][0]][k+sizes[i][1]]);
                }
            }
        }

        return ans;
    }
};
