class Solution {
public:
    int jump(vector<int>& nums) {
        // O(1) space
        // keep track of the max jump at each step
        int n=nums.size(), ans=0, mx=nums[0], loc=0;
        for (int i=0; i<n-1; i++) {
            mx = max(mx, i+nums[i]);
            if (i == loc) {
                ans++;
                loc = mx;
            }
        }
        return ans;
    }
};
