class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> delta(n, 0);

        int k = 0;
        for (int i=0; i<n; i++) {
            bool flag = nums[i] == val;

            k += flag;
            delta[i] = k;

            if (flag) nums[i] = -1;
        }

        for (int i=0; i<n; i++) {
            if (nums[i] == -1) continue;
            swap(nums[i-delta[i]], nums[i]);
        }

        return n-k;
    }
};
