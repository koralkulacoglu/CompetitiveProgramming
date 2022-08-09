class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size(), m=t.size(), cnt=0;
        if (n==0 && m==0) return true;
        for (int i=0; i<m; i++) {
            if (s[cnt] == t[i]) {
                cnt++;
            }
            if (cnt == n) return true;
        }
        return false;
    }
};
