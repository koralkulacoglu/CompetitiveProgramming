using tup = tuple<int, int, int, int, int>;

class Solution {
    const vector<int> dx = {-1, 1, 0, 0};
    const vector<int> dy = {0, 0, -1, 1};
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        
        auto inBounds = [&](int x, int y) {
            if (x < 0 || y < 0 || x >= n || y >= m) return false;
            return true;
        };
        
        vector<vector<vector<vector<int>>>> costs(n, vector<vector<vector<int>>>(m, vector<vector<int>>(4, vector<int>(k+1, 1e9))));
        priority_queue<tup, vector<tup>, greater<tup>> pq; // cost, k, dir, x, y
        costs[0][0][0][0] = grid[0][0];
        costs[0][0][1][0] = grid[0][0];
        costs[0][0][2][0] = grid[0][0];
        costs[0][0][3][0] = grid[0][0];
        pq.push({grid[0][0], 0, 0, 0, 0});
        pq.push({grid[0][0], 0, 1, 0, 0});
        pq.push({grid[0][0], 0, 2, 0, 0});
        pq.push({grid[0][0], 0, 3, 0, 0});
        while (!pq.empty()) {
            auto [cost, c, d, x, y] = pq.top();
            pq.pop();

            if (cost > costs[x][y][d][c]) continue;

            for (int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (!inBounds(nx, ny)) continue;
                int nd = i;
                int nc = c + (d != nd);
                if (nc > k) continue;
                
                int nCost = cost + grid[nx][ny];
                if (nCost >= costs[nx][ny][nd][nc]) continue;

                costs[nx][ny][nd][nc] = nCost;
                pq.push({nCost, nc, nd, nx, ny});
            }
        }

        int cost = 1e9;
        for (int i=0; i<4; i++) {
            int curCost = *min_element(costs[n-1][m-1][i].begin(), costs[n-1][m-1][i].end());
            cost = min(cost, curCost);
        }


        return cost < 1e9 ? cost : -1;
    }
};
