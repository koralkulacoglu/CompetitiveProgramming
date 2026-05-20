class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int mx = 0;
        for (int num : nums) {
            if (num >= mx) {
                mx = num;
                ans++;
            }
        }
        return ans;
    }
};
