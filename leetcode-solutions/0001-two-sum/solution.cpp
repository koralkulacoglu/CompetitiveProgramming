class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, int> seen;
        for (int i=0; i<n; i++) {
            int val = nums[i];
            if (seen[target - val]) return {i, seen[target-val]-1};
            seen[nums[i]] = i+1;
        }
        return {-1, -1};
    }
};
