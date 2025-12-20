class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        // we can move 1s left always
        // pick best 1s to the left of the rightmost 1
        int n = nums.size();

        long long ans = 0;
        multiset<int> best;
        for (int i=0; i<n; i++) {
            best.insert(nums[i]);
            if (s[i] == '1') {
                auto it = best.rbegin();
                int val = *it;
                ans += val;
                best.erase(prev(best.end()));
            }
        }

        return ans;
    }
};
