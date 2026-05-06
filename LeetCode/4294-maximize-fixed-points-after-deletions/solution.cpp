class Solution {
public:
    int maxFixedPoints(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> cand;
        for (int i=0; i<n; i++) {
            if (nums[i] <= i) cand.push_back({i - nums[i], nums[i]});
        }
        sort(cand.begin(), cand.end());
        vector<int> dp;
        for (auto&p : cand) {
            int val = p.second;
            auto it = lower_bound(dp.begin(), dp.end(), val);
            if (it == dp.end()) dp.push_back(val);
            else *it = val;
        }
        return dp.size();
    }
};
