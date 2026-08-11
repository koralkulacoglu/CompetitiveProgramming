// idea: binary search

class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        // precompute max square possible ending at each point
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = mat[i][j];
                    continue;
                }

                if (mat[i][j] == 0) continue;

                int up = dp[i-1][j];
                int left = dp[i][j-1];
                int upLeft = dp[i-1][j-1];

                dp[i][j] = 1 + min(up, min(left, upLeft));
            }
        }

        vector<vector<int>> dpB(n, vector<int>(m, 0));
        for (int i=n-1; i>=0; i--) {
            for (int j=m-1; j>=0; j--) {
                if (i == n-1 || j == m-1) {
                    dpB[i][j] = mat[i][j];
                    continue;
                }

                if (mat[i][j] == 0) continue;

                int up = dpB[i+1][j];
                int left = dpB[i][j+1];
                int upLeft = dpB[i+1][j+1];

                dpB[i][j] = 1 + min(up, min(left, upLeft));
            }
        }

        auto isPossible = [&](int k) {
            vector<pair<int, int>> coords;
            for (int i=0; i<n; i++) {
                for (int j=0; j<m; j++) {
                    if (dp[i][j] >= k) coords.emplace_back(i, j);
                }
            }

            int maxX=0, maxY=0;
            for (int i=0; i<n; i++) {
                for (int j=0; j<m; j++) {
                    if (dpB[i][j] >= k) {
                        maxX = max(maxX, i);
                        maxY = max(maxY, j);
                    }
                }
            }

            for (auto [x, y] : coords) {
                if (maxX > x) return true;
                if (maxY > y) return true;
            }

            return false;
        };

        int ans = 0;
        int l=1, r=min(n, m);
        while (l <= r) {
            int k = (l + r) / 2;

            if (isPossible(k)) {
                ans = max(ans, k);
                l = k + 1;
            }
            else r = k - 1;
        }

        return ans * ans;
    }
};
