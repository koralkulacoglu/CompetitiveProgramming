class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        for (int i : nums) ans += abs(i - nums[n/2]);
        return ans;
    }
};
