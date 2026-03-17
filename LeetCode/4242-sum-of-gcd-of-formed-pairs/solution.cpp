class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n);
        vector<int> mx(n);
        mx[0] = nums[0];
        prefixGcd[0] = nums[0];
        for (int i=1; i<n; i++) {
            mx[i] = max(mx[i-1], nums[i]);
            prefixGcd[i] = gcd(nums[i], mx[i]);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        long long ans = 0;
        for (int i=0; i<n/2; i++) ans += gcd(prefixGcd[i], prefixGcd[n-i-1]);
        return ans;
    }
};
