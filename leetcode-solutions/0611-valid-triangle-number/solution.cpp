/*
num < max + min
*/

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                int target = nums[i] + nums[j];
                auto ptr = lower_bound(nums.begin() + j + 1, nums.end(), target);
                ans += ptr - (nums.begin() + j + 1);
            }
        }
        return ans;
    }
};
