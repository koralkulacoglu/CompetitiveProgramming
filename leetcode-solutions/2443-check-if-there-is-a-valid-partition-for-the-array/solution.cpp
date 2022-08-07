class Solution {
public:
    bool validPartition(vector<int>& a) {
        int n = a.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for (int i=0; i<n; i++) {
            if (!dp[i]) continue;
            if (i < n-1 && a[i] == a[i+1]) dp[i+2] = true;
            if (i < n-2 && a[i] == a[i+1] && a[i+1] == a[i+2]) dp[i+3] = true;
            if (i < n-2 && a[i] == a[i+1]-1 && a[i+1] == a[i+2]-1) dp[i+3] = true;
        }
        return dp[n];
    }
};
