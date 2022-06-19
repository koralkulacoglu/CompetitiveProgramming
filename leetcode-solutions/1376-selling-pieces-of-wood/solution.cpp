void print(vector<vector<long long>> a) {
    for (vector<long long> &i : a) {
        for (long long &j : i) {
            cout << j << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

class Solution {
public:
    // dp for max of 1 element, new size, previous size
    // O(200^3)
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        map<pair<int, int>, int> costs;
        for (vector<int> &i: prices) costs[make_pair(i[1], i[0])] = max(costs[make_pair(i[1], i[0])], i[2]);
        
        vector<vector<long long>> dp(n+1, vector<long long>(m+1, 0));
        
        dp[0][0] = costs[make_pair(1, 1)];
        
        // 1D case
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                dp[i][j] = costs[make_pair(i, j)];
                dp[i][j] = max(dp[i][j], dp[i-1][j] + dp[1][j]);
                dp[i][j] = max(dp[i][j], dp[i][j-1] + dp[i][1]);
                
                for (int k=1; k<i; ++k)
                    dp[i][j]=max(dp[i][j], dp[k][j]+dp[i-k][j]);
                for (int k=1; k<j; ++k)
                    dp[i][j]=max(dp[i][j], dp[i][k]+dp[i][j-k]);
            }
        }
        // print(dp);
        
        return dp[n][m];
    }
};
