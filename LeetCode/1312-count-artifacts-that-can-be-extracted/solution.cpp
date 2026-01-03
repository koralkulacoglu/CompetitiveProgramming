class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& afs, vector<vector<int>>& dig) {
        vector<vector<bool>> a(n, vector<bool>(n, false));
        for (auto &i : dig) {
            a[i[0]][i[1]] = true;
        }
        int ans=0;
        for (auto &i : afs) {
            bool wk=true;
            for (int j=i[0]; j<=i[2]; j++) {
                for (int k=i[1]; k<=i[3]; k++) {
                    if (!a[j][k]) {
                        wk = false;
                        break;
                    }
                }
                if (!wk) break;
            }
            if (wk) ans++;
        }
        return ans;
    }
};
