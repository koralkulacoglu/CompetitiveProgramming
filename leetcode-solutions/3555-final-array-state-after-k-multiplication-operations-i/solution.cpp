class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        set<pair<int, int>> s;
        for (int i=0; i<n; i++) s.insert({nums[i], i});
        for (int i=0; i<k; i++) {
            auto [mn, idx] = *s.begin();
            s.erase(s.begin());
            mn *= multiplier;
            s.insert({mn, idx});
        }
        for (auto i : s) nums[i.second] = i.first;
        return nums;
    }
};
