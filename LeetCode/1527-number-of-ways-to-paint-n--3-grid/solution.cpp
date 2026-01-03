class Solution {
    int MOD = 1e9+7;

    bool isValid(int x) {
        int prevColor = -1;
        for (int i=0; i<3; i++) {
            int color = x%3;
            if (color == prevColor) return false;
            prevColor = color;
            x /= 3;
        }

        return true;
    }

    bool isValidPair(int x, int y) {
        if (!isValid(x) || !isValid(y)) return false;

        for (int i=0; i<3; i++) {
            int xColor = x%3;
            int yColor = y%3;
            if (xColor == yColor) return false;
            x /= 3;
            y /= 3;
        }

        return true;
    }

public:
    int numOfWays(int n) {
        vector<vector<int>> dp(n, vector<int>(27, 0));
        vector<vector<int>> compatible(27);
        for (int x=0; x<27; x++) {
            if (!isValid(x)) continue;
            dp[0][x] = 1;
            for (int y=0; y<27; y++) {
                if (!isValidPair(x, y)) continue;
                compatible[x].push_back(y);
            }
        }

        for (int i=1; i<n; i++) {
            for (int x=0; x<27; x++) {
                for (int y : compatible[x]) {
                    dp[i][x] += dp[i-1][y];
                    dp[i][x] %= MOD;
                }
            }
        }

        int ans = 0;
        for (int i : dp[n-1]) {
            ans += i;
            ans %= MOD;
        }

        return ans;
    }
};
