class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (auto& p : knowledge) mp[p[0]] = p[1];
        string word, res;
        for (char c : s) {
            if (c == ')') {
                auto it = mp.find(word);
                if (it == mp.end()) res += '?';
                else res += mp[word];
                word.clear();
            }
            else if (c == '(') {
                res += word;
                word.clear();
            }
            else {
                word += c;
            }
        }
        return res + word;
    }
};
