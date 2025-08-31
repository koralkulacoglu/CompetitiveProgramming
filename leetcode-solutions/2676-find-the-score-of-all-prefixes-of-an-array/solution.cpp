class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0);

        int mx = nums[0];
        ans[0] = nums[0] + mx;
        for (int i=1; i<n; i++) {
            mx = max(mx, nums[i]);
            ans[i] = nums[i] + mx;
        }

        for (int i=1; i<n; i++) ans[i] += ans[i-1];

        return ans;
    }
};
