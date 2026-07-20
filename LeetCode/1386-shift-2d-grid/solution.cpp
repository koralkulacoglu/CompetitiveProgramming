class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        auto shift = [&](int x, int y) {
            int val = x * m + y;
            val += k;
            val %= (n * m);
            return make_pair(val / m, val % m);
        };

        vector<vector<int>> arr(grid.begin(), grid.end());
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                auto [x, y] = shift(i, j);
                arr[x][y] = grid[i][j];
            }
        }

        return arr;
    }
};
