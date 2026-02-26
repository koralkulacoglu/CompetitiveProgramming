class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans;
        for (string t : dictionary) {
            int i = 0;
            for (char c : s) if (c == t[i]) i++;
            if (i >= t.size()) {
                if (ans.empty() || ans.size() < t.size() || (ans.size() == t.size() && t < ans)) {
                    ans = t;
                }
            }
        }
        return ans;
    }
};
