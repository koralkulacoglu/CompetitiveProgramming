class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> ones(n, vector<int>(m, 0));
        for (int i=0; i<n; i++) {
            ones[i][0] = matrix[i][0] - '0';
            for (int j=1; j<m; j++) ones[i][j] = (matrix[i][j] == '1' ? ones[i][j-1] + 1 : 0);
        }

        int ans = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                int width = 1e9;
                int height = 0;
                for (int k=i; k>=0; k--) {
                    height++;
                    width = min(width, ones[k][j]);
                    ans = max(ans, height * width);
                }
            }
        }
        
        return ans;
    }
};
