class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int num = nums[nums.size()/2];
        int ans = 0;
        for (int i : nums) ans += abs(num - i);

        return ans;
    }
};

