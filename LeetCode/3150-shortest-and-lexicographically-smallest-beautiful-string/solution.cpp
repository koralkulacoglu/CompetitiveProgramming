class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int m = 1e9;
        int ones = 0;
        for (int l=0, r=0; r<n; r++) {
            ones += s[r] == '1';
            while (ones > k || (s[l] == '0' && l < r)) ones -= s[l++] == '1';
            if (ones == k) m = min(m, r - l + 1);
        }

        string ans;
        for (int i=0; i<=n-m; i++) {
            string cur = s.substr(i, m);
            if (count(cur.begin(), cur.end(), '1') != k) continue;
            if (ans.empty() || cur < ans) ans = cur;
        }

        return ans;
    }
};
