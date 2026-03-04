class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return abs(a) > abs(b);
        });
        long long ans = 0;
        int n = nums.size();
        for (int i=0; i<(n+1)/2; i++) ans += ((long long) nums[i]) * nums[i];
        for (int i=(n+1)/2; i<n; i++) ans -= ((long long) nums[i]) * nums[i];
        return ans;
    }
};

