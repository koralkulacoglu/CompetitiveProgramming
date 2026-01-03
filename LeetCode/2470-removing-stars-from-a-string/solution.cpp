class Solution {
public:
    string removeStars(string s) {
        string res;
        int wait = 0;
        int n = s.size();
        for (int i=n-1; i>=0; i--) {
            if (s[i] == '*') {
                wait++;
                continue;
            }
            if (!wait) {
                res += s[i];
            }
            else {
                wait--;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
