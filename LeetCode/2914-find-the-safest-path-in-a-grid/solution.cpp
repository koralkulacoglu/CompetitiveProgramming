typedef pair<int, int> pi;

class Solution {
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> safeness(n, vector<int>(n, 1e9));

        queue<tuple<int, int, int>> q;
        for (int i{0}; i<n; i++) {
            for (int j{0}; j<n; j++) {
                if (grid[i][j]) {
                    safeness[i][j] = 0;
                    q.push({i, j, 0});
                }
            }
        }

        while (!q.empty()) {
            auto [x, y, factor] = q.front();
            q.pop();

            for (int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nFactor = factor + 1;

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (safeness[nx][ny] <= nFactor) continue;

                safeness[nx][ny] = nFactor;
                q.push({nx, ny, nFactor});
            }
        }

        auto cmp = [&](pi a, pi b) {
            return safeness[a.first][a.second] < safeness[b.first][b.second];
        };
        priority_queue<pi, vector<pi>, decltype(cmp)> pq(cmp);
        pq.push({0, 0});

        vector<vector<int>> cost(n, vector<int>(n, -1));
        cost[0][0] = safeness[0][0];

        while (!pq.empty()) {
            auto [x, y] = pq.top();
            pq.pop();

            for (int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (cost[nx][ny] != -1) continue;

                cost[nx][ny] = min(cost[x][y], safeness[nx][ny]);
                pq.push({nx, ny});
            }
        }

        return cost[n-1][n-1];
    }
};
