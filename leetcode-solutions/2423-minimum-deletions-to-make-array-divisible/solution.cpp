class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(), nums.end());
        set<int> vals(nums.begin(), nums.end()), divs(numsDivide.begin(), numsDivide.end());
        for (int i : divs) {
            for (int j : vals) {
                if (i%j) {
                    vals.erase(j);
                }
            }
        }
        if (vals.empty()) return -1;
        int ans=1e9;
        for (int i : vals) {
            int idx = lower_bound(nums.begin(), nums.end(), i) - nums.begin();
            ans = min(ans, idx);
        }
        return ans;
    }
};
