class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        multiset<int> dpVals;
        dpVals.insert(dp[0]);
        for (int i=1; i<n; i++) {
            if (i - k - 1 >= 0) {
                auto ptr = dpVals.find(dp[i - k - 1]);
                dpVals.erase(ptr);
            }

            int best = *dpVals.rbegin();

            dp[i] = max(nums[i], best + nums[i]);
            dpVals.insert(dp[i]);
        }

        return *max_element(dp.begin(), dp.end());
    }
};

