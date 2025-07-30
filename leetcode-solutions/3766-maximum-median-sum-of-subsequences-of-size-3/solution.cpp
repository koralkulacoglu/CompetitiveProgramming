class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        long long ans = 0;
        for (int i=n-2; i>=n/3; i-=2) {
            ans += nums[i];
        }

        // cout << ans << endl;

        return ans;
    }
};
