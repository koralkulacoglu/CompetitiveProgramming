class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        vector<int> psa(n+1);
        sort(nums.begin(), nums.end());
        for (int i=1; i<=n; i++) {
            psa[i] = psa[i-1] + nums[i-1];
        }
        vector<int> res;
        for (int i : queries) {
            int idx = upper_bound(psa.begin(), psa.end(), i) - psa.begin() - 1;
            res.push_back(idx);
        }
        return res;
    }
};
