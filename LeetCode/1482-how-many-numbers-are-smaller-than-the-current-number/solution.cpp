class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sorted(nums.begin(), nums.end());
        sort(sorted.begin(), sorted.end());
        vector<int> res;
        for (int i : nums) {
            int idx = lower_bound(sorted.begin(), sorted.end(), i) - sorted.begin();
            res.push_back(idx);
        }
        return res;
    }
};
