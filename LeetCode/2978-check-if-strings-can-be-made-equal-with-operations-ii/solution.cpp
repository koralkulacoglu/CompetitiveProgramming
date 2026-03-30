class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        unordered_map<char, int> f1e, f1o, f2e, f2o;
        for (int i=0; i<n; i++) {
            if (i%2) {
                f1o[s1[i]]++;
                f2o[s2[i]]++;
            }
            else {
                f1e[s1[i]]++;
                f2e[s2[i]]++;
            }
        }
        for (char c='a'; c<='z'; c++) {
            if (f1o[c] != f2o[c]) return false;
            if (f1e[c] != f2e[c]) return false;
        }
        return true;
    }
};
