class Solution {
public:
    int countPartitions(vector<int>& nums) {
        return (nums.size()-1) * !(accumulate(nums.begin(), nums.end(), 0) % 2);
    }
};
