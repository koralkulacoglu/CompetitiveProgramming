class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int cur = 0, sum = 0;
        for (int i=0; i<n; i++) {
            cur += i * nums[i];
            sum += nums[i];
        }
        int ans = cur;
        for (int i=1; i<n; i++) {
            cur += sum - n * nums[n-i];
            ans = max(ans, cur);
        }
        return ans;
    }
};
