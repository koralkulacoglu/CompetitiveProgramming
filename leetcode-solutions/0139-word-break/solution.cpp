class Solution {
public:
    unordered_map<string, bool> words;
    unordered_map<string, bool> seen;
    bool recur(string s) {
        int n=s.size();
        if (n == 0) return true;
        if (seen[s]) return false;
        seen[s] = true;
        string cur;
        for (int i=0; i<n; i++) {
            cur += s[i];
            if (words[cur] && recur(s.substr(i+1))) return true;
        }
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        for (string &i : wordDict) words[i] = true;
        return recur(s);
    }
};
