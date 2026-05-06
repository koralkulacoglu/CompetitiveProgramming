class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();
        vector<vector<char>> a(n, vector<char>(m));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                a[i][j] = boxGrid[m-j-1][i];
            }
        }
        vector<vector<int>> psa(n, vector<int>(m, 0));
        for (int j=0; j<m; j++) psa[0][j] = (a[0][j] == '#');
        for (int i=1; i<n; i++) {
            for (int j=0; j<m; j++) {
                psa[i][j] = psa[i-1][j];
                if (a[i][j] == '*') psa[i][j] = 0;
                else if (a[i][j] == '#') psa[i][j]++;
            }
        }
        for (int j=0; j<m; j++) {
            int stones = psa[n-1][j];
            for (int i=n-1; i>=0; i--) {
                if (a[i][j] == '*') {
                    if (i) stones = psa[i-1][j];
                    continue;
                }
                if (stones) {
                    a[i][j] = '#';
                    stones--;
                }
                else a[i][j] = '.';
            }
        }
        return a;
    }
};
