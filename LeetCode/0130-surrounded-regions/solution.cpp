class Solution {
public:
    int n, m;
    vector<vector<char>> a;
    vector<vector<bool>> outer;
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    void dfs(int x, int y) {
        outer[x][y] = true;

        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx<0 || nx>=n || ny<0 || ny>=m || a[nx][ny] == 'X') continue;

            if (!outer[nx][ny]) dfs(nx, ny);
        }
    }

    void solve(vector<vector<char>>& board) {
        // first generate a mapping of which O's touch edges

        n = board.size();
        m = board[0].size();
        
        a = board;
        outer.assign(n, vector<bool>(m, false));

        for (int i=0; i<n; i++) {
            if (board[i][0] == 'O' && !outer[i][0]) dfs(i, 0);
            if (board[i][m-1] == 'O' && !outer[i][m-1]) dfs(i, m-1);
        }

        for (int i=0; i<m; i++) {
            if (board[0][i] == 'O' && !outer[0][i]) dfs(0, i);
            if (board[n-1][i] == 'O' && !outer[n-1][i]) dfs(n-1, i);
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (!outer[i][j]) board[i][j] = 'X';
            }
        }
    }
};
