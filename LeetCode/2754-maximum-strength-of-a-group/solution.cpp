class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        bool used = false;
        long long ans = 1;
        for (int i=1; i<n; i+=2) {
            if (nums[i] >= 0) break;
            ans *= nums[i-1] * nums[i];
            used = true;
        }
        for (int i=n-1; i>=0; i--) {
            if (nums[i] <= 0) break;
            ans *= nums[i];
            used = true;
        }
        return (used ? ans : *max_element(nums.begin(), nums.end()));
    }
};
