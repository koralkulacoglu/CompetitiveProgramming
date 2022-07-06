class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    
    int n, m;
    vector<vector<int>> a;
    vector<vector<bool>> vis;
    void dfs(int x, int y, int orig, int col) {
        a[x][y] = col;
        vis[x][y] = true;
        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx<0 || nx>=n || ny<0 || ny>=m || vis[nx][ny] || a[nx][ny] != orig) continue;
            dfs(nx, ny, orig, col);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n=image.size(), m=image[0].size();
        a = image;
        vis.clear();
        vis.resize(n, vector<bool>(m, false));
        dfs(sr, sc, a[sr][sc], color);
        return a;
    }
};
