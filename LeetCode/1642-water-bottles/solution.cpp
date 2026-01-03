class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int numEmpty = 0;
        while (numBottles) {
            ans += numBottles;
            numEmpty += numBottles;
            numBottles = numEmpty / numExchange;
            numEmpty = numEmpty % numExchange;
        }
        return ans;
    }
};
