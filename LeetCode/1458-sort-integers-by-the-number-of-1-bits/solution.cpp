class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int x, int y) {
            int bx = __builtin_popcount(x);
            int by = __builtin_popcount(y);
            if (bx != by) return bx < by;
            return x < y;
        });
        return arr;
    }
};

