class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> taken(n, false);
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (!taken[j] && baskets[j] >= fruits[i]) {
                    taken[j] = true;
                    fruits[i] = 0;
                    break;
                }
            }
        }

        int ans = 0;
        for (int i : fruits) ans += (i > 0);

        return ans;
    }
};
