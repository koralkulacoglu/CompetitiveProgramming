class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        unordered_map<int, bool> fixed;
        int ans = 0;
        int n = nums.size();
        for (int i=0; i<n; i++) {
            if (nums[i] != target[i] && !fixed[nums[i]]) {
                fixed[nums[i]] = true;
                ans++;
            }
        }
        return ans;
    }
};
