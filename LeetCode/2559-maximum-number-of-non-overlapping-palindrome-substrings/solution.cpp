// idea: greedy, always take earliest palindrome >= k

class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int j=0; j<n; j++) {
            for (int i=0; i<=j; i++) {
                if (s[i] != s[j]) continue;

                if (i >= j-1) isPal[i][j] = true;
                if (j > 0 && i < n-1 && isPal[i+1][j-1]) isPal[i][j] = true;
            }
        }

        int ans = 0;
        int idx = -1;
        for (int i=0; i<n; i++) {
            for (int j=0; j<=i; j++) {
                int s = i - j + 1;
                if (s < k) continue;
                if (j <= idx) continue;
                if (!isPal[j][i]) continue;

                ans++;
                idx = i;
            }
        }

        return ans;
    }
};
