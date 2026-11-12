class Solution {
    int lis(vector<int>& nums) {
        int n=nums.size(), ans=1, cur=1;
        for (int i=1; i<n; i++) {
            if (nums[i] > nums[i-1]) cur++;
            else cur = 1;
            ans = max(ans, cur);
        }
        reverse(nums.begin(), nums.end());
        return ans;
    }
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        return max(lis(nums), lis(nums));
    }
};
