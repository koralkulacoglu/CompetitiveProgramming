class Solution {
public:
    int maximumRows(vector<vector<int>>& mat, int cols) {
        int n = mat.size(), m = mat[0].size();
        int ans = 0;
        for (int i=0; i<pow(2, 14); i++) {
            if (__builtin_popcount(i) != cols) continue;
            
            int cnt = 0;
            for (int j=0; j<n; j++) {
                bool wk = true;
                for (int k=0; k<m; k++) {
                    if (mat[j][k] && !(i & (1<<(k)))) {
                        wk = false;
                        break;
                    }
                }
                cnt += wk;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
