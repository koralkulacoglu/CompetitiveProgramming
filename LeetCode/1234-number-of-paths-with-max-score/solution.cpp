class Solution {
    int MOD = 1e9 + 7;
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(m, {0, 0}));
        dp[0][0] = {0, 1};
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (board[i][j] == 'X') continue;
                if (i > 0 && dp[i-1][j].second) {
                    int prevAmount = dp[i-1][j].second;
                    int prevScore = dp[i-1][j].first + (isdigit(board[i][j]) ? board[i][j] - '0' : 0);
                    int curScore = dp[i][j].first;

                    if (prevScore > curScore) {
                        dp[i][j].first = prevScore;
                        dp[i][j].second = prevAmount;
                    }
                    else if (prevScore == curScore) {
                        dp[i][j].second += prevAmount;
                        dp[i][j].second %= MOD;
                    }
                }
                if (j > 0 && dp[i][j-1].second) {
                    int prevAmount = dp[i][j-1].second;
                    int prevScore = dp[i][j-1].first + (isdigit(board[i][j]) ? board[i][j] - '0' : 0);
                    int curScore = dp[i][j].first;

                    if (prevScore > curScore) {
                        dp[i][j].first = prevScore;
                        dp[i][j].second = prevAmount;
                    }
                    else if (prevScore == curScore) {
                        dp[i][j].second += prevAmount;
                        dp[i][j].second %= MOD;
                    }
                }
                if (i > 0 && j > 0 && dp[i-1][j-1].second) {
                    int prevAmount = dp[i-1][j-1].second;
                    int prevScore = dp[i-1][j-1].first + (isdigit(board[i][j]) ? board[i][j] - '0' : 0);
                    int curScore = dp[i][j].first;

                    if (prevScore > curScore) {
                        dp[i][j].first = prevScore;
                        dp[i][j].second = prevAmount;
                    }
                    else if (prevScore == curScore) {
                        dp[i][j].second += prevAmount;
                        dp[i][j].second %= MOD;
                    }
                }
            }
        }

        return {dp[n-1][m-1].first, dp[n-1][m-1].second};
    }
};
