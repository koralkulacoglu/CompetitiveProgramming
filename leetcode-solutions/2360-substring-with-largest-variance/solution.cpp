class Solution {
public:
    int largestVariance(string s) {
        int n=s.size(), ans=0;
        for (int i=0; i<26; i++) {
            for (int j=0; j<26; j++) {
                if (i == j) continue;
                int a=0, b=0;
                for (int k=0; k<n; k++) {
                    a += (s[k]-'a') == i;
                    b += (s[k]-'a') == j;
                    if (b > a) {
                        a = 0;
                        b = 0;
                    }
                    if (b) ans = max(ans, a-b);
                }
                a = 0;
                b = 0;
                for (int k=n-1; k>=0; k--) {
                    a += (s[k]-'a') == i;
                    b += (s[k]-'a') == j;
                    if (b > a) {
                        a = 0;
                        b = 0;
                    }
                    if (b) ans = max(ans, a-b);
                }
            }
        }
        return ans;
    }
};
