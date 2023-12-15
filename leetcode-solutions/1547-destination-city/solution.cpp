class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, bool> seen;
        for (auto i : paths) {
            seen[i[0]] = false;
            if (seen.find(i[1]) == seen.end()) {
                seen[i[1]] = true;
            }
        }
        string ans;
        for (auto i : seen) {
            if (i.second) ans = i.first;
        }
        return ans;
    }
};
