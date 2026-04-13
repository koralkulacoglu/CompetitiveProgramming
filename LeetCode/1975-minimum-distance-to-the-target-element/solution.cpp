class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = 1e9;
        int n = nums.size();
        for (int i=0; i<n; i++) {
            if (nums[i] == target) ans = min(ans, abs(i - start));
        }
        return ans;
    }
};
