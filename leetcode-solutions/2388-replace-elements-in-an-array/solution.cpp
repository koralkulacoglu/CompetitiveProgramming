class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& ops) {
        int n = nums.size();
        unordered_map<int, int> ptr;
        for (int i=0; i<n; i++) {
            ptr[nums[i]] = i;
        }
        for (vector<int> i : ops) {
            int n1=i[0], n2=i[1];
            auto nodeHandler = ptr.extract(n1);
            nodeHandler.key() = n2;
            ptr.insert(std::move(nodeHandler));
        }
        for (auto &i : ptr) {
            int num = i.first;
            int idx = i.second;
            nums[idx] = num;
        }
        return nums;
    }
};
