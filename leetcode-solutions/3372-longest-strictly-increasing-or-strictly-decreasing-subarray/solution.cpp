class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1, cur = 1, n = nums.size();
        for (int i=1; i<n; i++) {
            if (nums[i] > nums[i-1]) cur++;
            else cur = 1;
            ans = max(ans, cur);
        }

        cur = 1;
        for (int i=1; i<n; i++) {
            if (nums[i] < nums[i-1]) cur++;
            else cur = 1;
            ans = max(ans, cur);
        }

        return ans;
    }
};
