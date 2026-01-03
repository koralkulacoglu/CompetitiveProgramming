class Solution {
public:
    void print(vector<int> a) {
        for (int &i : a) cout << i << ' ';
        cout << '\n';
    }
    
    int maxProfit(vector<int>& a) {
        int n=a.size();
        if (n == 1) return 0;
        vector<int> dp(n, 0);
        dp[1] = max(0, a[1]-a[0]);
        for (int i=2; i<n; i++) {
            dp[i] = dp[i-1];
            for (int j=0; j<i; j++) {
               dp[i] = max(dp[i], a[i] - a[j] + (j-2>=0?dp[j-2]:0));
            }
        }
        // print(dp);
        return dp[n-1];
    }
};
