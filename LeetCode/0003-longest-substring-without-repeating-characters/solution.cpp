class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        map<char, bool> seen;
        int i = 0, ans = 0;
        for (int j=0; j<n; j++) {
            if (seen[s[j]]) {
                while (s[i] != s[j]) {
                    seen[s[i]] = false;
                    i++;
                }
                i++;
            }
            ans = max(ans, j - i + 1);
            seen[s[j]] = true;
        }

        return ans;
    }
};
