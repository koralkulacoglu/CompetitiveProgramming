class Solution {
    vector<vector<int>> res;

    void dfs(vector<int> nums, vector<int> cur) {
        if (nums.empty()) {
            res.push_back(cur);
            return;
        }

        int n = nums.size();
        for (int i=0; i<n; i++) {
            int num = nums[i];
            vector<int> newNums = nums, newCur = cur;
            newNums.erase(newNums.begin() + i);
            newCur.push_back(num);
            dfs(newNums, newCur);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        dfs(nums, {});
        return res;
    }
};
