class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;
        int n=nums.size(), mx=nums[0];
        for (int i=0; i<n; i++) {
            if (i > mx) return false;
            mx = max(mx, i+nums[i]);
            if (mx >= n-1) return true;
        }
        return mx==n-1;
    }
};
