class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n=nums.size(), ans=1;
        sort(nums.begin(), nums.end());
        int mx=0, mn=1e9;
        for (int i=0; i<n; i++) {
            mx = max(mx, nums[i]);
            mn = min(mn, nums[i]);
            if (mx - mn > k) {
                mx=nums[i]; mn=nums[i];
                ans++;
            }
        }
        return ans;
    }
};
