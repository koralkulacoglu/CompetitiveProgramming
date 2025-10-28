class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int> psa(n+1); psa[0] = 0;
        for (int i=1; i<=n; i++) psa[i] = psa[i-1] + nums[i-1];

        int ans = 0;
        for (int i=0; i<n; i++) {
            if (nums[i]) continue;
            int diff = abs(2*psa[i+1] - psa[n]);
            if (diff == 1) ans++;
            if (diff == 0) ans += 2;
        }

        return ans;
    }
};
