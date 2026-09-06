class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        long long sum = accumulate(nums.begin(), nums.begin() + n/2, 0LL);
        int ans = sum > total - sum;
        for (int i=0; i<n-1; i++) {
            sum -= nums[i];
            sum += nums[(i + n/2) % n];
            ans += sum > total - sum;
        }
        return ans;
    }
};
