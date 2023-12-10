class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> a(m, vector<int>(n));

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                a[i][j] = matrix[j][i];
            }
        }

        return a;
    }
};
