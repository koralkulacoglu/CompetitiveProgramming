class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        unordered_map<int, bool> full;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (fruits[i] <= baskets[j] && !full[j]) {
                    full[j] = true;
                    break;
                }
            }
        }
        
        return n - full.size();
    }
};
