class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end(), greater<int>());
        sort(discounts.begin(), discounts.end(), greater<int>());

        int n = prices.size();
        int m = discounts.size();
        double ans = 0;
        for (int i=0; i<n; i++) {
            double price = prices[i];
            if (i < m) price *= (100.0 - discounts[i]) / 100.0;
            ans += price;
        }

        return ans;
    }
};
