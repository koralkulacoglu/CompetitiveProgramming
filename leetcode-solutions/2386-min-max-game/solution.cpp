class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        while (nums.size() > 1) {
            vector<int> nNums;
            bool mn=true;
            for (int i=0; i<nums.size(); i+=2) {
                if (mn) nNums.push_back(min(nums[i], nums[i+1]));
                else nNums.push_back(max(nums[i], nums[i+1]));
                mn = !mn;
            }
            nums = nNums;
        }
        return nums[0];
    }
};
