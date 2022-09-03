class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        map<int, bool> seen;
        for (int i=0; i<nums.size()-1; i++) {
            int sm = nums[i] + nums[i+1];
            if (seen[sm]) return true;
            seen[sm] = true;
        }
        return false;
    }
};
