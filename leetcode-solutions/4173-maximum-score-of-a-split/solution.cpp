class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();

        vector<int> sMin(n); sMin[n-1] = nums[n-1];
        for (int i=n-2; i>=0; i--) sMin[i] = min(sMin[i+1], nums[i]);

        long long ans = -1e18;
        long long psa = 0;
        for (int i=0; i<n-1; i++) {
            psa += nums[i];
            ans = max(ans, psa - sMin[i+1]);
        }

        return ans;
    }
};
