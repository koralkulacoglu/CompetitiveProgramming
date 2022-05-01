class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n=s.size();
        for (int i=0; i<n; i++) {
            if (s[i] == '#') {
                if (i == 0) {
                    s.erase(i, 1);
                }
                else {
                    s.erase(i-1, 2);
                    n--;
                    i-=2;
                }
                n--;
            }
        }
        for (int i=0; i<n; i++) {
            if (s[i] == '#') {
                s.erase(i, 1);
                i--;
            }
        }
        n=t.size();
        for (int i=0; i<n; i++) {
            if (t[i] == '#') {
                if (i == 0) {
                    t.erase(i, 1);
                }
                else {
                    t.erase(i-1, 2);
                    n--;
                    i-=2;
                }
                n--;
            }
        }
        for (int i=0; i<n; i++) {
            if (t[i] == '#') {
                t.erase(i, 1);
                i--;
            }
        }
        // cout << s << ' ' << t;
        return s == t;
    }
};
