class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());

        int ans = 0;
        int x = 0;
        int i = 0;
        while (x < target) {
            if (i < coins.size() && coins[i] <= x + 1) {
                x += coins[i];
                i++;
            } else {
                x += (x + 1);
                ans++;
            }
        }

        return ans;
    }
};
