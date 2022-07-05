/*
The greatest common divisor of any adjacent values in the sequence is equal to 1.

There is at least a gap of 2 rolls between equal valued rolls. More formally, if the value of the ith roll is equal to the value of the jth roll, then abs(i - j) > 2.
*/

class Solution {
public:
    long long MOD = 1e9 + 7;
    // some sort of dp
    // dp[i] = number of distinct rolls
    // dp[i] = dp[i-1] * dp[2] - cases where 
    int distinctSequences(int n) {
        if (n == 1) return 6;
        
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(6, vector<long long>(6, 0)));
        for (int i=0; i<6; i++) {
            for (int j=0; j<6; j++) {
                if (__gcd(i+1, j+1)==1 && i!=j) {
                    dp[2][i][j]++;
                }
            }
        }
        // third dimension for previous val
        for (int i=3; i<=n; i++) {
            for (int j=0; j<6; j++) {
                for (int k=0; k<6; k++) {
                    for (int l=0; l<6; l++) {
                        if (__gcd(j+1, k+1)==1 && j!=k && j!=l) {
                            dp[i][k][j] += dp[i-1][l][k];
                            dp[i][k][j] %= MOD;
                        }
                    }
                }
            }
        }
        long long ans=0;
        for (int i=0; i<6; i++) {
            for (int j=0; j<6; j++) {
                ans += dp[n][i][j];
                ans %= MOD;
            }
        }
        return ans;
    }
};
