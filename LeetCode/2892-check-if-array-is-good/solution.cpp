class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.back();
        for (int i=0; i<n; i++) {
            if (nums[i] != i+1) return false;
        }
        int m = nums.size();
        if (m - n != 1) return false;
        for (int i=n; i<m; i++) {
            if (nums[i] != n) return false;
        }
        return true;
    }
};
