class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i=1; i<n; i++) {
            for (int j=0; j<m; j++) {
                int val = 1e9;
                val = matrix[i-1][j];
                if (j>0) val = min(val, matrix[i-1][j-1]);
                if (j<m-1) val = min(val, matrix[i-1][j+1]);
                matrix[i][j] += val;
            }
        }
        int ans = 1e9;
        for (int j=0; j<m; j++) {
            ans = min(ans, matrix[n-1][j]);
        }
        return ans;
    }
};
