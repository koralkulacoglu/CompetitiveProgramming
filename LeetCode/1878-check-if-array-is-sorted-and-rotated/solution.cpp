class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        vector<int> a = nums;
        for (int i : nums) a.push_back(i);

        int idx = 0;
        int prev = 0;
        for (int i : a) {
            if (i >= prev) {
                idx++;
                if (idx == n) return true;
                prev = i;
            }
            else {
                idx = 1;
                prev = i;
            }
        }

        return false;
    }
};
