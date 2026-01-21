// 0001110
// 0010000
// 0011110

// 011

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        for (int i=0; i<n; i++) {
            if ((nums[i] & 1) == 0) continue;

            // find last 1 bit after zeros, set it to 0
            int temp = nums[i];
            int bit = 0;

            while (temp & 1) {
                temp >>= 1;
                bit++;
            }

            ans[i] = nums[i] - pow(2, bit-1);
        }

        return ans;
    }
};
