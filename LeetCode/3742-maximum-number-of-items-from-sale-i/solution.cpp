class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> copies(n, 0);
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) copies[i] += !(items[j][0] % items[i][0]);
        vector<int> dp(budget+1, 0), ndp;
        if (items[0][1] <= budget) dp[items[0][1]] = copies[0];
        for (int i=1; i<n; i++) {
            ndp = dp;
            for (int j=0; j<=budget; j++) {
                int newCost = j + items[i][1];
                if (newCost > budget) continue;
                ndp[newCost] = max(ndp[newCost], dp[j] + copies[i]);
            }
            dp = ndp;
        }
        int minPrice = 1e9, ans = 0;
        for (auto& p : items) minPrice = min(minPrice, p[1]);
        for (int i=0; i<=budget; i++) ans = max(ans, dp[i] + (budget - i) / minPrice);
        return ans;
    }
};
