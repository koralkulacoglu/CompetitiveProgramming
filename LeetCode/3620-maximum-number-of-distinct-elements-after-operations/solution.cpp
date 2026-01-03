class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 1;
        int lb = nums[0] - k;
        for (int i=1; i<n; i++) {
            if (lb > nums[i] + k) continue;
            if (lb + 1 > nums[i] + k) continue;
            lb = max(lb + 1, nums[i] - k);
            ans++;
        }
        return ans;
    }
};
