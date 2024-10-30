class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp_f(n, 1);
        for (int i=0; i<n; i++) {
            for (int j=0; j<i; j++) {
                if (nums[j] < nums[i] && dp_f[i] < dp_f[j]+1) dp_f[i] = dp_f[j] + 1;
            }
        }

        vector<int> dp_b(n, 1);
        for (int i=n-1; i>=0; i--) {
            for (int j=n-1; j>i; j--) {
                if (nums[j] < nums[i] && dp_b[i] < dp_b[j]+1) dp_b[i] = dp_b[j] + 1;
            }
        }

        int ans = n;
        for (int i=1; i<n-1; i++) {
            if (dp_f[i] > 1 && dp_b[i] > 1) ans = min(ans, n - (dp_f[i] + dp_b[i] - 1));
        }

        return ans;
    }
};

