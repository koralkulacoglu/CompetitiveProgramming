class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int mx=0, mx2=0, idx=0, i;
        for (int j=0; j<nums.size(); j++) {
            i = nums[j];
            if (i > mx) {
                mx2 = mx;
                mx = i;
                idx = j;
            }
            else if (i <= mx) {
                mx2 = max(mx2, i);
            }
        }
        return ((mx>=mx2*2)?idx:-1);
    }
};
