class Solution {
    int n = 1e5;
    array<bool, (int)1e5+1> dp;
    bool comp = false;

    void precomp() {
        dp.fill(false);
        dp[1] = true;
        for (int i=2; i<=n; i++) {
            for (int s=1; s*s<=i; s++) {
                if (!dp[i - s*s]) {
                    dp[i] = true;
                    break;
                }
            }
        }
    }
    
public:
    bool winnerSquareGame(int n) {
        if (!comp) {
            precomp();
            comp = true;
        }

        return dp[n];
    }
};
