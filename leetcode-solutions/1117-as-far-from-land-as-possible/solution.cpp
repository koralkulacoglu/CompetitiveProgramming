class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    int maxDistance(vector<vector<int>>& a) {
        int n=a.size();
        vector<vector<int>> vis(n, vector<int>(n, 1e9));
        queue<vector<int>> que;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (a[i][j]) {
                    vis[i][j] = 0;
                    que.push({i, j, 0});
                }
            }
        }
        while (!que.empty()) {
            vector<int> node = que.front();
            que.pop();
            int x = node[0];
            int y = node[1];
            int dist = node[2];
            for (int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx>=0 && nx<n && ny>=0 && ny<n && dist+1 < vis[nx][ny]) {
                    vis[nx][ny] = min(vis[nx][ny], dist+1);
                    que.push({nx, ny, dist+1});
                }
            }
        }
        int ans=-1;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (!a[i][j]) {
                    ans = max(ans, vis[i][j]);
                }
            }
        }
        return ans!=1e9?ans:-1;
    }
};
