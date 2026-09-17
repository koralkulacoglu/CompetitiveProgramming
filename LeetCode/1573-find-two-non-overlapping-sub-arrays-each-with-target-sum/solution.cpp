// idea: go right -> left then left -> right
// then use 2-ptr

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int l = 0;
        int sum = 0;
        vector<int> minLen(n, 1e9);
        for (int r=0; r<n; r++) {
            if (r > 0) minLen[r] = minLen[r-1];
            sum += arr[r];
            while (sum > target) {
                sum -= arr[l];
                l++;
            }
            if (sum == target) minLen[r] = min(minLen[r], r - l + 1);
        }

        int r = n-1;
        sum = 0;
        int ans = 1e9;
        for (int l=n-1; l>=0; l--) {
            sum += arr[l];
            while (sum > target) {
                sum -= arr[r];
                r--;
            }
            if (sum == target && l > 0) ans = min(ans, minLen[l-1] + r - l + 1);
        }

        return ans < 1e9 ? ans : -1;
    }
};
