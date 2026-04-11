class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> mp(n+1);
        for (int i=0; i<n; i++) mp[nums[i]].push_back(i);
        int ans = 1e9;
        for (vector<int> x : mp) {
            int m = x.size();
            for (int i=0; i+2<m; i++) ans = min(ans, abs(x[i] - x[i+1]) + abs(x[i] - x[i+2]) + abs(x[i+1] - x[i+2]));
        }
        return ans < 1e9 ? ans : -1;
    }
};
