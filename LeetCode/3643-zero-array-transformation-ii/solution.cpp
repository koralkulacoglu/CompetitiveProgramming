class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        auto check = [&](int k) {
            vector<int> psa(n+1, 0);

            for (int i=0; i<k; i++) {
                int l = queries[i][0];
                int r = queries[i][1];
                int val = queries[i][2];

                psa[l] += val;
                psa[r + 1] -= val;
            }

            int cap = 0;
            for (int i=0; i<n; i++) {
                cap += psa[i];
                if (cap < nums[i]) return false;
            }

            return true;
        };

        int l=0, r=queries.size(), ans = -1;
        while (l <= r) {
            int k = (l + r) / 2;
            if (check(k)) r = k - 1, ans = k;
            else l = k + 1;
        }

        return ans;
    }
};
