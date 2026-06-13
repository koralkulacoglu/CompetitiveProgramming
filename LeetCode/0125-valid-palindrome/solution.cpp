class Solution {
    string preProcess(string s) {
        string ns;
        for (char c : s) {
            if (isalnum(c)) ns.push_back(tolower(c));
        }
        return ns;
    }
public:
    bool isPalindrome(string s) {
        s = preProcess(s);
        int n = s.size();
        for (int i=0; i<n/2; i++) if (s[i] != s[n-i-1]) return false;
        return true;
    }
};
