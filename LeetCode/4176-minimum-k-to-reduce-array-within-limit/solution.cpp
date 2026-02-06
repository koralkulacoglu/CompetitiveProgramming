class Solution {
    long long nonPositive(vector<int>& nums, int k) {
        long long ans = 0;
        for (int i : nums) {
            ans += (i + k - 1) / k;
        }
        return ans;
    }
    
public:
    int minimumK(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        long long l=1, r=1e9;
        while (l <= r) {
            long long k = (l + r) / 2;

            if (nonPositive(nums, k) <= k*k) {
                ans = k;
                r = k-1;
            }
            else l = k+1;
        }

        return ans;
    }
};
