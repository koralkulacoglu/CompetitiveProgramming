class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        vector<int> dp(n,0);
        int ans=0;
        for(int i=1; i<n; i++) {
            dp[i] = values[i]+values[i-1]-1;
            dp[i] = max(dp[i], dp[i-1]-1+values[i]-values[i-1]);
            ans = max(dp[i], ans);
        }
        return ans;
    }
};
