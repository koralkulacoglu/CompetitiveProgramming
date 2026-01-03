class Solution {
public:
    long long minimumCost(long long cost1, long long cost2, long long costBoth, int need1, int need2) {
        if (cost1 + cost2 <= costBoth) return cost1 * need1 + cost2 * need2;

        long long mn = min(need1, need2);
        
        long long cost = costBoth * mn;

        need1 -= mn;
        need2 -= mn;

        if (need1 > 0) {
            long long mnCost = min(cost1, costBoth);
            cost += need1 * mnCost;
        }

        if (need2 > 0) {
            long long mnCost = min(cost2, costBoth);
            cost += need2 * mnCost;
        }

        return cost;
    }
};
