class Solution {
public:
    vector<int> sortArray(vector<int>& nums, int bit=31) {
        if (nums.size() <= 1 || bit < 0) return nums;

        vector<int> zero, one;
        for (int i : nums) {
            if ((i >> bit) & 1) one.push_back(i);
            else zero.push_back(i);
        }

        sortArray(zero, bit - 1);
        sortArray(one, bit - 1);

        nums.clear();

        if (bit == 31) {
            nums.insert(nums.end(), one.begin(), one.end());
            nums.insert(nums.end(), zero.begin(), zero.end());
        } else {
            nums.insert(nums.end(), zero.begin(), zero.end());
            nums.insert(nums.end(), one.begin(), one.end());
        }

        return nums;
    }
};
