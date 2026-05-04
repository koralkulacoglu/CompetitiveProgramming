class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        vector<int> ones(32, 0), zeros(32, 0);
        for (int i : nums) {
            for (int j=0; j<32; j++) {
                if (i & 1) {
                    ans += zeros[j];
                    ones[j]++;
                }
                else {
                    ans += ones[j];
                    zeros[j]++;
                }
                i >>= 1;
            }
        }
        return ans;
    }
};
