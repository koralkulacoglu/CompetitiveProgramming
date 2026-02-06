class Solution {
public:
    int minRemoval(vector<int>& nums, long long k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = 1e9;
        for (int i=0; i<n; i++) {
            int idx = upper_bound(nums.begin(), nums.end(), nums[i] * k) - nums.begin();
            ans = min(ans, max(0, i + n - idx));
        }

        return ans;
    }
};

