class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n = arr.size();
        long long totalSum = accumulate(arr.begin(), arr.end(), 0);

        if (k == 1) {
            // find max subarray without any repeats
            vector<int> dp(n, -1e9);
            dp[0] = arr[0];
            int ans = max(0, dp[0]);
            for (int i=1; i<n; i++) {
                dp[i] = max(arr[i], dp[i-1] + arr[i]);
                ans = max(ans, dp[i]);
            }
            return ans;
        }

        if (k == 2 || totalSum < 0) {
            // find max subarray without any repeats
            arr.insert(arr.end(), arr.begin(), arr.end());
            n *= 2;
            vector<long long> dp(n, -1e9);
            dp[0] = arr[0];
            long long ans = max(0LL, dp[0]);
            for (int i=1; i<n; i++) {
                dp[i] = max((long long)arr[i], dp[i-1] + arr[i]);
                ans = max(ans, dp[i]);
            }
            return ans%((long long)1e9+7);
        }

        long long curSum=0, mxSum=-1e9;
        for (int i=0; i<n; i++) {
            curSum += arr[i];
            if (curSum >= mxSum) {
                mxSum = curSum;
            }
        }
        long long curSumB=0, mxSumB=-1e9;
        for (int i=n-1; i>=0; i--) {
            curSumB += arr[i];
            if (curSumB >= mxSumB) {
                mxSumB = curSumB;
            }
        }

        long long ans = totalSum*(k-2)%((long long)1e9+7);
        ans += mxSum;
        ans %= (long long)1e9+7;
        ans += mxSumB;
        ans %= (long long)1e9+7;
        return ans;
    }
};
