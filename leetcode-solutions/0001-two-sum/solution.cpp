class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> seen;
        int n = nums.size();
        for (int i=0; i<n; i++) {
            if (seen[target - nums[i]]) return {seen[target - nums[i]]-1, i};
            seen[nums[i]] = i+1;
        }
        return {-1, -1};
    }
};
