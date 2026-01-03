class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        multiset<int> vals;
        for (vector<int> i : matrix) {
            for (int j : i) {
                vals.insert(j);
            }
        }
        for (int i : vals) {
            k--;
            if (!k) return i;
        }
        return -1;
    }
};
