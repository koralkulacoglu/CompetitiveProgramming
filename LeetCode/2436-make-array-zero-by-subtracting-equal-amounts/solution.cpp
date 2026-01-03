class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int> vals;
        for (int i : nums) vals.insert(i);
        vals.erase(0);
        return vals.size();
    }
};
