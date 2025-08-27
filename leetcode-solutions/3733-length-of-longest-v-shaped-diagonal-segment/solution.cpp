class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        auto inb = [&](int r, int c){ return 0 <= r && r < n && 0 <= c && c < m; };

        vector<int> dr = {-1, 1, 1, -1};
        vector<int> dc = { 1, 1,-1, -1};
        vector<int> cw = {1, 2, 3, 0};

        vector run2(4, vector(n, vector<int>(m, 0)));
        vector run0(4, vector(n, vector<int>(m, 0)));

        auto fill_runs_for_dir = [&](int d){
            int rstep = -dr[d], cstep = -dc[d];

            vector<pair<int,int>> starts;
            starts.reserve(n*m);
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    if (!inb(i + dr[d], j + dc[d])) starts.emplace_back(i, j);

            for (auto [si, sj] : starts) {
                int i = si, j = sj;
                while (inb(i, j)) {
                    int fi = i + dr[d], fj = j + dc[d];
                    int next2 = inb(fi, fj) ? run2[d][fi][fj] : 0;
                    int next0 = inb(fi, fj) ? run0[d][fi][fj] : 0;
                    int v = grid[i][j];
                    if (v == 2) {
                        run2[d][i][j] = 1 + next0;
                        run0[d][i][j] = 0;
                    } else if (v == 0) {
                        run0[d][i][j] = 1 + next2;
                        run2[d][i][j] = 0;
                    } else {
                        run2[d][i][j] = run0[d][i][j] = 0;
                    }
                    i += rstep; j += cstep;
                }
            }
        };

        for (int d = 0; d < 4; ++d) fill_runs_for_dir(d);

        bool anyOne = false;
        for (auto& row : grid) for (int v : row) if (v == 1) { anyOne = true; break; }
        if (!anyOne) return 0;

        int ans = 1;

        for (int sr = 0; sr < n; ++sr) {
            for (int sc = 0; sc < m; ++sc) {
                if (grid[sr][sc] != 1) continue;

                for (int d1 = 0; d1 < 4; ++d1) {
                    int i = sr + dr[d1], j = sc + dc[d1];
                    if (!inb(i, j) || grid[i][j] != 2) continue;

                    int len = 1;
                    int expected = 0;

                    int d2 = cw[d1];

                    while (true) {
                        ans = max(ans, 1 + len);

                        int ni = i + dr[d2], nj = j + dc[d2];
                        if (inb(ni, nj)) {
                            if (expected == 0) {
                                ans = max(ans, 1 + len + run0[d2][ni][nj]);
                            } else {
                                ans = max(ans, 1 + len + run2[d2][ni][nj]);
                            }
                        }

                        int ni1 = i + dr[d1], nj1 = j + dc[d1];
                        if (!inb(ni1, nj1)) break;
                        int v = grid[ni1][nj1];
                        if (v != expected) break;
                        i = ni1; j = nj1;
                        ++len;
                        expected = (expected == 0 ? 2 : 0);
                    }
                }
            }
        }

        return ans;
    }
};
