class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        vector<int> bits(31, 0);
        for (int num : nums) {
            for (int i=0; i<31; i++) {
                bits[i] += ((num >> i) & 1);
            }
        }

        int ans = 0;
        for (int i=0; i<31; i++) {
            if (bits[i] >= k) ans += (1 << i);
        }

        return ans;
    }
};
