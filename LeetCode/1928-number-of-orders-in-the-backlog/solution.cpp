class Solution {
    static constexpr int MOD{(int)1e9 + 7};

    struct Order {
        int price;
        int amount;
        bool isSell;

        Order(int price, int amount, bool isSell) : price(price), amount(amount), isSell(isSell) {}

        bool operator<(const Order& other) const {
            if (isSell) return price > other.price;
            return price < other.price;
        }

        bool isMatch(Order& other) {
            if (isSell == other.isSell) return false;
            if (isSell && price <= other.price) return true;
            if (!isSell && price >= other.price) return true;
            return false;
        }

        void match(Order& other) {
            int matchAmount = min(amount, other.amount);

            amount -= matchAmount;
            other.amount -= matchAmount;

            /*
            cout << "Taker: " << "price = " << price << ", amount = " << amount << ", isSell = " << int(isSell) << endl;
            cout << "Maker: " << "price = " << other.price << ", amount = " << other.amount << ", isSell = " << int(other.isSell) << endl;
            cout << endl;
            */
        }
    };

public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<Order> buys, sells;

        for (auto& o : orders) {
            Order order(o[0], o[1], o[2]);

            auto& book = (order.isSell ? buys : sells);

            while (!book.empty()) {
                Order best = book.top();

                if (order.isMatch(best)) {
                    book.pop();
                    order.match(best);
                    
                    if (best.amount > 0) {
                        book.push(best);
                    }
                    if (order.amount == 0) {
                        break;
                    }
                }
                else break;
            }

            auto& insertBook = (order.isSell ? sells : buys);

            // insert order if not empty;
            if (order.amount > 0) {
                insertBook.push(order);
            }
        }

        int ans = 0;

        while (!buys.empty()) {
            Order o = buys.top();
            buys.pop();
            ans += o.amount;
            ans %= MOD;
        }

        while (!sells.empty()) {
            Order o = sells.top();
            sells.pop();
            ans += o.amount;
            ans %= MOD;
        }

        return ans;
    }
};

