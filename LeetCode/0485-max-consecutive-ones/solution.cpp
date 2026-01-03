class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int ones = 0;
        for (int i : nums) {
            if (i) {
                ones++;
                ans = max(ans, ones);
            }
            else ones = 0;
        }
        return ans;
    }
};
