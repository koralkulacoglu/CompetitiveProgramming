class Solution {
public:
    vector<string> cancer;
    map<string, bool> word;
    void dfs(string cur, string rem) {
        int n = rem.size();
        if (n == 0) {
            cancer.push_back(cur);
            return;
        }
        string xd;
        for (int i=0; i<n; i++) {
            xd += rem[i];
            if (word[xd]) {
                dfs(cur == "" ? xd : cur + " " + xd, rem.substr(i+1));
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> temp;
        map<string, bool> temp2;
        cancer = temp;
        word = temp2;
        for (string i : wordDict) word[i] = true;
        dfs("", s);
        return cancer;
    }
};
