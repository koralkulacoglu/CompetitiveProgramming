class Solution {
public:
    vector<int> a, dp;
    vector<bool> vis;
    int recur(int val) {
        if (val < 0) return 0;
        if (val == 0) return 1;
        if (vis[val]) return dp[val];
        
        for (int i : a) {
            int curVal = val - i;
            dp[val] += recur(curVal);
        }
        vis[val] = true;
        
        return dp[val];
    }
    int combinationSum4(vector<int>& nums, int target) {
        dp.clear();
        dp.resize(target+1, 0);
        
        vis.clear();
        vis.resize(target+1, false);
        
        a = nums;
        
        return recur(target);
    }
};
