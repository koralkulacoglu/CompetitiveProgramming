class Solution {
    int MOD = 1e9 + 7;
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<pair<int, int>> buys;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> sells;

        for (vector<int>& order : orders) {
            int price = order[0];
            int amount = order[1];
            int orderType = order[2];

            if (orderType == 0) buys.push({price, amount});
            else sells.push({price, amount});

            while (!buys.empty() && !sells.empty()) {
                auto bestBuy = buys.top();
                int buyPrice = bestBuy.first;
                int buyAmount = bestBuy.second;

                auto bestSell = sells.top();
                int sellPrice = bestSell.first;
                int sellAmount = bestSell.second;

                if (buyPrice < sellPrice) break;

                buys.pop();
                sells.pop();

                int amount = min(buyAmount, sellAmount);
                buyAmount -= amount;
                sellAmount -= amount;

                if (buyAmount > 0) buys.push({buyPrice, buyAmount});
                if (sellAmount > 0) sells.push({sellPrice, sellAmount});
            }
        }

        int ans = 0;
        while (!buys.empty()) {
            int amount = buys.top().second;
            buys.pop();
            ans += amount;
            ans %= MOD;
        }

        while (!sells.empty()) {
            int amount = sells.top().second;
            sells.pop();
            ans += amount;
            ans %= MOD;
        }

        return ans;
    }
};
