class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> psa(n, 0);
        for (int i=0; i<n-1; i++) psa[i+1] = nums[i] ? psa[i] + 1 : 0;

        /*
        for (int i : psa) cout << i << ' ';
        cout << endl;
        */

        int ones = 0;
        int ans = 0;
        for (int i=n-1; i>=0; i--) {
            int p = psa[i];
            int curAns = p + ones;

            ans = max(ans, curAns);

            ones = nums[i] ? ones+1 : 0;
        }

        return ans;
    }
};
