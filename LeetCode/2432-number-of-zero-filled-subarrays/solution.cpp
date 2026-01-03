class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int zeros = 0;
        for (int i=0; i<n; i++) {
            if (nums[i] == 0) {
                zeros++;
                ans += zeros;
            }
            else {
                zeros = 0;
            }
        }

        return ans;
    }
};
