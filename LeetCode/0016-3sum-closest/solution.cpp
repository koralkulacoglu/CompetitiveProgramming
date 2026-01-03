class Solution {
public:
    bool check(int a, int b) {
        // check if a is within the bounds 0 to b
        if (a < 0) return false;
        if (a >= b) return false;
        return true;
    }

    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int i=1; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                int sum = nums[i] + nums[j];
                int val = target - sum;
                
                // binary search for the closest number to target. O(nlog(n))
                int idx = lower_bound(nums.begin(), nums.begin()+i-1, val) - nums.begin();
                
                // 2 candidate values
                if (check(idx, n) && abs(target - (sum + nums[idx])) < abs(target - ans)) {
                    if (idx < i) ans = sum + nums[idx];
                }
                if (check(idx+1, n) && abs(target - (sum + nums[idx+1])) < abs(target - ans)) {
                    if (idx+1 < i) ans = sum + nums[idx+1];
                }
                if (check(idx-1, n) && abs(target - (sum + nums[idx-1])) < abs(target - ans)) {
                    if (idx-1 < i) ans = sum + nums[idx-1];
                }
                // cout << idx << ' ' << i << ' ' << j << '\n';
            }
        }
        return ans;
    }
};
