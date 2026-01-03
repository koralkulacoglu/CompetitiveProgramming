class Solution {
public:
    int n, m;
    vector<int> dx = {0, -1, 1, 0};
    vector<int> dy = {1, 0, 0, -1};
    map<pair<int, int>, bool> seen;
    vector<vector<char>> a;

    void dfs(int x, int y) {
        seen[{x, y}] = true;
        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx>=0 && nx<n && ny>=0 && ny<m && a[nx][ny] == '1' && !seen[{nx, ny}]) dfs(nx, ny);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        seen.clear();
        a = grid;

        int ans = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (a[i][j] == '1' && !seen[{i, j}]) {
                    dfs(i, j);
                    ans++;
                }
            }
        }

        return ans;
    }
};
