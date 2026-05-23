class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int mx, mn;
        int n = nums.size();
        int ans = 1e9;
        for (int x=0; x<k; x++) {
            for (int y=0; y<k; y++) {
                if (x == y) continue;
                int cur = 0;
                for (int i=0; i<n; i++) {
                    int val = nums[i] % k;
                    if (i%2) {
                        mn = min(y, val);
                        mx = max(y, val);
                    }
                    else {
                        mn = min(x, val);
                        mx = max(x, val);
                    }
                    int ops = min(mx - mn, mn + k - mx);
                    cur += ops;
                }
                ans = min(ans, cur);
            }
        }
        return ans;
    }
};
