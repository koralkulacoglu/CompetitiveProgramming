class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();

        vector<int> dp(n, 1);
        for (int i=1; i<n; i++) {
            if (arr[i] > arr[i-1]) dp[i] = dp[i-1] + 1;
        }

        vector<int> dpB(n, 1);
        for (int i=n-2; i>=0; i--) {
            if (arr[i] > arr[i+1]) dpB[i] = dpB[i+1] + 1;
        }

        int ans = 0;
        for (int i=0; i<n; i++) {
            if (dp[i] > 1 && dpB[i] > 1 && dp[i] + dpB[i] > 3) ans = max(ans, dp[i] + dpB[i] - 1);
        }

        return ans;
    }
};
