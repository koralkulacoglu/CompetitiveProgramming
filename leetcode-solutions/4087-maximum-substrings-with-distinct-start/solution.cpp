class Solution {
public:
    int maxDistinct(string s) {
        unordered_map<char, bool> seen;
        int ans = 0;
        int n = s.size();
        for (char c : s) {
            if (seen[c]) continue;
            ans++;
            seen[c] = true;
        }
        return ans;
    }
};
