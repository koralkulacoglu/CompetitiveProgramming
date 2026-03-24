class Solution {
    int MOD = 12345;
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<long long>> res(n, vector<long long>(m));
        long long prod = 1;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                res[i][j] = prod;
                prod *= grid[i][j];
                prod %= MOD;
            }
        }
        prod = 1;
        for (int i=n-1; i>=0; i--) {
            for (int j=m-1; j>=0; j--) {
                res[i][j] *= prod;
                res[i][j] %= MOD;
                prod *= grid[i][j];
                prod %= MOD;
            }
        }
        vector<vector<int>> xd(n, vector<int>(m));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                xd[i][j] = res[i][j];
            }
        }
        return xd;
    }
};
