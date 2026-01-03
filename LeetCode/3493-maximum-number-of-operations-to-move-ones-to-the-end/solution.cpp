class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        int ans = 0;
        int ones = (s[0] == '1');
        for (int i=1; i<n; i++) {
            if (s[i] == '1') {
                if (s[i-1] == '0') ans += ones;
                ones++;
            }
        }

        if (s[n-1] == '0') ans += ones;

        return ans;
    }
};
