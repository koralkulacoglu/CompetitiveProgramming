class Solution {
public:
    string removeDuplicates(string s) {
        string t;
        for (char c : s) {
            if (!t.empty() && c == t.back()) t.pop_back();
            else t.push_back(c);
        }
        return t;
    }
};
