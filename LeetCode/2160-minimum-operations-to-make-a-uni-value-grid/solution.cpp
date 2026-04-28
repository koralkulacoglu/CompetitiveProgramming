class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        int val = grid[0][0];
        vector<int> vals;
        for (vector<int>& r : grid) {
            for (int& c : r) {
                if (abs(val - c) % x) return -1;
                vals.push_back(c);
            }
        }
        sort(vals.begin(), vals.end());
        int v = vals[vals.size()/2];
        int ans = 0;
        for (int i : vals) ans += abs(v - i) / x;
        return ans;
    }
};
