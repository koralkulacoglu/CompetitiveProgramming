class Solution {
public:
    int climbStairs(int n) {
        vector<int> res(max(n, 2), 0);
        res[0] = 1;
        res[1] = 2;
        for (int i=2; i<n; i++) {
            res[i] = res[i-1] + res[i-2];
        }
        return res[n-1];
    }
};
