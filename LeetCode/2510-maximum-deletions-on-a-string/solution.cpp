class Solution {
public:
    int deleteString(string s) {
        /*
        int n = s.size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i=0; i<n; i++) {
            if (dp[i]) {
                for (int dist=1; dist<=(n-i)/2; dist++) {
                    if (s.substr(i, dist) == s.substr(i+dist, dist)) {
                        dp[i+dist] = max(dp[i+dist], dp[i] + 1);
                    }
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
        */

        int n = s.size(), BASE = 31;
        reverse(s.begin(), s.end());
        vector<int> dp(n+1);
        dp[1] = 1;
        for(int i = 2 ; i <= n; i++){
            dp[i] = 1;
            unsigned long long a = s[i-1]-'a', b = s[i-2]-'a', pow = 1;
            if(a == b) dp[i] = max(dp[i], 1+dp[i-1]);
            for(int j = 2; j <= i/2; j++){
                a = a*BASE+(s[i-j]-'a');
                b = (b-(s[i-j]-'a')*pow)*BASE*BASE+(s[i-j-j+1]-'a')*BASE+(s[i-j-j]-'a');
                pow *= BASE;
                if(a == b) dp[i] = max(dp[i], 1+dp[i-j]);
            }
        }
        return dp[n];
    }
};
