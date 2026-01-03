class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> ans(n-k+1);
        multiset<int> ms;
        for (int i=0; i<k; i++) ms.insert(nums[i]);
        ans[0] = *ms.rbegin();

        for (int i=k; i<n; i++) {
            ms.erase(ms.find(nums[i-k]));
            ms.insert(nums[i]);
            ans[i-k+1] = *ms.rbegin();
        }

        return ans;
    }
};
