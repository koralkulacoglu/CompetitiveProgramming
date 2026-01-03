class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res = "";
        set<int> vals;
        for (int i : spaces) vals.insert(i);
        for (int i=0; i<s.size(); i++) {
            if (!vals.empty() && i == *vals.begin()) {
                vals.erase(vals.begin());
                res += ' ';
            }
            res += s[i];
        }
        return res;
    }
};
