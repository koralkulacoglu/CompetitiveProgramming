class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (i==j || n-i-1==j) {
                    if (grid[i][j]==0) return false;
                }
                else if (grid[i][j]!=0) return false;
            }
        }
        return true;
    }
};
