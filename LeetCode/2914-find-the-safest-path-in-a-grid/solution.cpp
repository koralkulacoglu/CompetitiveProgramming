class Solution {
public:
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Step 1: Multi-source BFS to compute safeness from all danger cells
        vector<vector<int>> safeness(n, vector<int>(m, 1e9));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j] == 1) {
                    safeness[i][j] = 0;
                    q.push({i, j});
                }

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && safeness[nx][ny] > safeness[x][y] + 1) {
                    safeness[nx][ny] = safeness[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        // Step 2: Binary search on safeness factor
        int low = 0, high = n + m, ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            queue<pair<int, int>> q2;

            if (safeness[0][0] < mid) {
                high = mid - 1;
                continue;
            }

            visited[0][0] = true;
            q2.push({0, 0});

            while (!q2.empty()) {
                auto [x, y] = q2.front(); q2.pop();
                for (int k = 0; k < 4; ++k) {
                    int nx = x + dx[k], ny = y + dy[k];
                    if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                        !visited[nx][ny] && safeness[nx][ny] >= mid) {
                        visited[nx][ny] = true;
                        q2.push({nx, ny});
                    }
                }
            }

            if (visited[n-1][m-1]) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};

