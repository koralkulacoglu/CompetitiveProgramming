class StockSpanner {
    stack<pair<int, int>> prices; // value, how many items its greater than

public:
    int next(int price) {
        int count = 1;
        while (!prices.empty() && price >= prices.top().first) {
            count += prices.top().second;
            prices.pop();
        }

        prices.push({price, count});

        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
