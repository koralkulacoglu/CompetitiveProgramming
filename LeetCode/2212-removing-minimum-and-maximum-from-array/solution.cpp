class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mi = min_element(nums.begin(), nums.end()) - nums.begin();
        int ma = max_element(nums.begin(), nums.end()) - nums.begin();
        int l = min(mi, ma);
        int r = max(mi, ma);
        int ans = 1e9;
        ans = min(ans, r + 1);
        ans = min(ans, n - l);
        ans = min(ans, l + 1 + n - r);
        return ans;
    }
};
