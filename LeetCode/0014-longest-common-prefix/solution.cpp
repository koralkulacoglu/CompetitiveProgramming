class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res="";
        int n=strs.size();
        int m=1e9;
        for (int i=0; i<n; i++) m = min(m, (int)strs[i].size());
        for (int i=0; i<m; i++) {
            bool wk=true;
            for (int j=0; j<n; j++) {
                if (strs[0][i] != strs[j][i]) {
                    wk = false;
                    break;
                }
            }
            if (!wk) return res;
            res += strs[0][i];
        }
        return res;
    }
};
