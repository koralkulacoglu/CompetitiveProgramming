class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> a(n);
        for (int i=0; i<n; i++) a[i] = {nums[i], i};
        sort(a.begin(), a.end());

        vector<bool> marked(n, false);
        long long ans = 0;
        for (int i=0; i<n; i++) {
            int idx = a[i].second;
            if (marked[idx]) continue;

            ans += a[i].first;
            marked[idx] = true;
            if (idx > 0) marked[idx-1] = true;
            if (idx < n-1) marked[idx+1] = true;
        }

        return ans;
    }
};
