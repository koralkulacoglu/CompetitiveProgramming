class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int j = 0;
        int n = s.size();
        map<char, bool> seen;
        for (int i=0; i<n; i++) {
            if (seen[s[i]]) {
                while (s[j] != s[i]) {
                    seen[s[j]] = false;
                    j++;
                }
                j++;
            }
            seen[s[i]] = true;
            ans = max(ans, i-j+1);
            // cout << i << ' ' << j << '\n';
        }
        return ans;
    }
};
