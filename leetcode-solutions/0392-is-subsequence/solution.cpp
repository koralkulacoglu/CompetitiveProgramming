class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=t.size(), m=s.size(), idx=0;
        for (int i=0; i<n; i++) {
            if (idx == n) return true;
            if (s[idx] == t[i]) {
                idx++;
            }
        }
        return idx == m;
    }
};
