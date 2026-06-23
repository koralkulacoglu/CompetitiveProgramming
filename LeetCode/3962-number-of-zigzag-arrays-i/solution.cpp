class Solution {
    int MOD = 1e9 + 7;
    int leftBound, rightBound;

    int coord(int x) {
        return x - leftBound;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        leftBound = l;
        rightBound = r;
        vector<vector<long long>> dp(r-l+1, vector<long long>(2, 0)); // inc, dec
        vector<vector<long long>> newDp(r-l+1, vector<long long>(2, 0)); // inc, dec

        for (int i=l; i<=r; i++) {
            dp[coord(i)][0] = i - l;
            dp[coord(i)][1] = r - i;
        }

        for (int i=2; i<n; i++) {
            long long psa = 0;
            // newDp.clear();
            // vector<vector<long long>> newDp(r+1, vector<long long>(2, 0));
            for (int j=l; j<=r; j++) {
                newDp[coord(j)][0] = psa;
                psa += dp[coord(j)][1];

                newDp[coord(j)][0] %= MOD;
                psa %= MOD;
            }
            psa = 0;
            for (int j=r; j>=l; j--) {
                newDp[coord(j)][1] = psa;
                psa += dp[coord(j)][0];

                newDp[coord(j)][1] %= MOD;
                psa %= MOD;
            }

            dp = newDp;
        }

        long long ans = 0;
        for (int i=l; i<=r; i++) {
            ans += dp[coord(i)][0] + dp[coord(i)][1];
            ans %= MOD;
        }

        return ans;
    }
};

