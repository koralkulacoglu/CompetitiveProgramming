class Solution {
public:
    vector<long long> dp;
    long long coloredCells(int n) {
        // 1, 5, 13, ...
        // 1, 2, 3, ...
        // f(n) = 4n + f(n-1)

        if (dp.empty()) {
            dp.resize(1e5+1);
            dp[0] = 1;
            for (int i=1; i<n; i++) dp[i] = dp[i-1] + 4*i;
        }

        return dp[n-1];
    }
};
