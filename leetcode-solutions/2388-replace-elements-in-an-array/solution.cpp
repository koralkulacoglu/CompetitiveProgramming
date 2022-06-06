class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& ops) {
        int n=nums.size();
        unordered_map<int, int> idx;
        for (int i=0; i<n; i++) idx[nums[i]] = i;
        for (vector<int> &i : ops) {
            auto nodeHandler = idx.extract(i[0]);
            nodeHandler.key() = i[1];
            idx.insert(std::move(nodeHandler));
        }
        for (auto &i : idx) nums[i.second] = i.first;
        return nums;
    }
};
