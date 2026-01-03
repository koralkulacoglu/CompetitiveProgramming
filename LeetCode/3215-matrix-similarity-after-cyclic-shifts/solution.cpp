class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                int idx = 0;
                if (j%2 == 0) {
                    idx = (j+k)%m;
                }
                else {
                    idx = (m*100 + (j-k))%m;
                }
                if (mat[i][j] != mat[i][idx]) {
                    return false;
                }
            }
        }
        return true;
    }
};
