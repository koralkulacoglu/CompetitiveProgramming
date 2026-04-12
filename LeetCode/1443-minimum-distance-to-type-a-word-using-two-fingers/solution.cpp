class Solution {
    int dist(int a, int b) {
        if (a == 26 || b == 26) return 0;
        return abs(a/6 - b/6) + abs(a%6 - b%6);
    }

public:
    int minimumDistance(string word) {
        int n = word.size();
        vector<int> dp(27, 1e9);
        dp[26] = 0;
        for (int i = 1; i < n; i++) {
            int cur = word[i] - 'A';
            int prev = word[i-1] - 'A';
            vector<int> ndp(27, 1e9);
            for (int j = 0; j < 27; j++) {
                ndp[j] = min(ndp[j], dp[j] + dist(prev, cur));
                ndp[prev] = min(ndp[prev], dp[j] + dist(j, cur));
            }
            dp = ndp;
        }
        return *min_element(dp.begin(), dp.end());
    }
};
