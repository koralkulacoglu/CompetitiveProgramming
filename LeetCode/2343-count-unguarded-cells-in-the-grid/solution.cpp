class Solution {
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    bool isValid(int x, int y, vector<vector<bool>>& walled) {
        int m = walled.size();
        int n = walled[0].size();
        if (x<0 || x>=m || y<0 || y>=n) return false;
        if (walled[x][y]) return false;
        return true;
    }

public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<bool>> blocked(m, vector<bool>(n, false));
        for (auto& w : walls) blocked[w[0]][w[1]] = true;
        for (auto& g : guards) blocked[g[0]][g[1]] = true;

        vector<vector<bool>> guarded(m, vector<bool>(n, false));
        for (auto& g : guards) {
            for (int d=0; d<4; d++) {
                int x = g[0] + dx[d];
                int y = g[1] + dy[d];

                while (isValid(x, y, blocked)) {
                    guarded[x][y] = true;
                    x += dx[d];
                    y += dy[d];
                }
            }
        }

        int ans = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                ans += !blocked[i][j] && !guarded[i][j];
            }
        }

        return ans;
    }
};
