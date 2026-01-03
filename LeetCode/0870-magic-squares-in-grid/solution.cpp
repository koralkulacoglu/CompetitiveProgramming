class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        auto isMagic = [&](int x, int y) {
            int r1 = grid[x][y] + grid[x+1][y] + grid[x+2][y];
            int r2 = grid[x][y+1] + grid[x+1][y+1] + grid[x+2][y+1];
            int r3 = grid[x][y+2] + grid[x+1][y+2] + grid[x+2][y+2];
            if (r1 != r2 || r1 != r3 || r2 != r3) return false;

            int c1 = grid[x][y] + grid[x][y+1] + grid[x][y+2];
            int c2 = grid[x+1][y] + grid[x+1][y+1] + grid[x+1][y+2];
            int c3 = grid[x+2][y] + grid[x+2][y+1] + grid[x+2][y+2];
            if (c1 != c2 || c1 != c3 || c2 != c3) return false;

            int d1 = grid[x][y] + grid[x+1][y+1] + grid[x+2][y+2];
            int d2 = grid[x][y+2] + grid[x+1][y+1] + grid[x+2][y];
            if (d1 != d2) return false;

            vector<bool> seen(9, false);
            for (int i=x; i<x+3; i++) {
                for (int j=y; j<y+3; j++) {
                    if (grid[i][j] > 9 || grid[i][j] < 1) return false;
                    seen[grid[i][j]-1] = true;
                }
            }

            for (bool i : seen) {
                if (!i) return false;
            }

            return true;
        };

        int ans = 0;
        for (int i=0; i<n-2; i++) {
            for (int j=0; j<m-2; j++) {
                ans += isMagic(i, j);
            }
        }

        return ans;
    }
};
