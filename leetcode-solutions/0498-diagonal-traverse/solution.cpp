class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> res;
        for (int i = 0; i < n + m - 1; i++) {
            for (int j = 0; j <= i; j++) {
                int r = j;
                int c = i - j;
                if (r < n && c < m) res.push_back(mat[r][c]);
            }
            if (i % 2 == 0) {
                int start = res.size();
                int len = 0;
                for (int j = 0; j <= i; j++) {
                    int r = j, c = i - j;
                    if (r < n && c < m) len++;
                }
                reverse(res.end() - len, res.end());
            }
        }

        return res;
    }
};

