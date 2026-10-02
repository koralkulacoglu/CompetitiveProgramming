class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        int n = s1.size();
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        bool wk = true;
        for (int i=0; i<n; i++) {
            if (s1[i] > s2[i]) {
                wk = false;
                break;
            }
        }
        if (wk) return true;
        wk = true;
        for (int i=0; i<n; i++) {
            if (s2[i] > s1[i]) {
                wk = false;
                break;
            }
        }
        return wk;
    }
};
