class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& a) {
        int n=a.size(), m=a[0].size();
        vector<vector<pair<bool, bool>>> vis(n, vector<pair<bool, bool>>(m, make_pair(false, false)));
        queue<vector<int>> que;
        for (int i=0; i<n; i++) {
            vis[i][0].first = true;
            vis[i][m-1].second = true;
            que.push({i, 0, 0});
            que.push({i, m-1, 1});
        }
        for (int i=0; i<m; i++) {
            vis[0][i].first = true;
            vis[n-1][i].second = true;
            que.push({0, i, 0});
            que.push({n-1, i, 1});
        }
        while (!que.empty()) {
            vector<int> node = que.front();
            que.pop();
            int x = node[0];
            int y = node[1];
            int o = node[2];
            for (int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx>=0 && nx<n && ny>=0 && ny<m && a[x][y] <= a[nx][ny]) {
                    if ((vis[nx][ny].first && !o) || (vis[nx][ny].second && o)) continue;
                    vis[nx][ny].first = vis[nx][ny].first || !o;
                    vis[nx][ny].second = vis[nx][ny].second || o;
                    que.push({nx, ny, o});
                }
            }
        }
        vector<vector<int>> res;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (vis[i][j].first && vis[i][j].second) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};
