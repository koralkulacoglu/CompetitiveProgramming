class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int zeros = 0;
        int left = 0;
        for (int right=0; right<n; right++) {
            zeros += (nums[right] == 0);
            while (zeros > k) {
                zeros -= (nums[left] == 0);
                left++;
            }

            ans = max(ans, right - left + 1);
        }
        
        return ans;
    }
};
