class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        int m = 100 / k + 2;
        vector<bool> mults(m, false);
        for (int num : nums) {
            if (num % k == 0) mults[num / k] = true;
        }
        for (int i=1; i<m; i++) {
            if (!mults[i]) return i * k;
        }
        return -1;
    }
};
