class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        auto digitSum = [](int x) {
            int sm = 0;
            while (x) {
                sm += x % 10;
                x /= 10;
            }
            return sm;
        };
        int n = nums.size();
        for (int i=0; i<n; i++) {
            if (digitSum(nums[i]) == i) return i;
        }
        return -1;
    }
};
