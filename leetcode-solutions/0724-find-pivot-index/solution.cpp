class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sm = accumulate(nums.begin(), nums.end(), 0);
        int cm=0;
        for (int i=0; i<n; i++) {
            cm += nums[i];
            if (cm == sm) return i;
            sm -= nums[i];
      }
        return -1;
    }
};
