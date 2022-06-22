class Solution {
public:
    bool strongPasswordCheckerII(string p) {
        string sc="!@#$%^&*()-+";
        if (p.size() < 8) return false;
        bool lc=false, uc=false, d=false, s=false;
        for (char &i : p) {
            if (isdigit(i)) d = true;
            if (islower(i)) lc = true;
            if (isupper(i)) uc = true;
            if (sc.find(i) != string::npos) s = true;
        }
        for (int i=1; i<p.size(); i++) {
            if (p[i] == p[i-1]) return false;
        }
        return d && lc && uc && s;
    }
};
