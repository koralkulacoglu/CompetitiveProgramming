class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        int m = wordDict.size();
        map<string, bool> words;
        for (string i : wordDict) words[i] = true;
        
        string word;
        vector<bool> dp(n, false);
        for (int i=0; i<n; i++) {
            for (int j=0; j<=i; j++) {
                if (dp[j]) word = s.substr(j+1, i-j);
                else word = s.substr(0, i+1);
                if (words[word]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n-1];
    }
};
