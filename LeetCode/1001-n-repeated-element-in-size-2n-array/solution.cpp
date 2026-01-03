class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size() / 2;
        vector<int> vals(1e4+1);
        for (int i : nums) vals[i]++;

        for (int i=0; i<=1e4; i++) {
            if (vals[i] == n) return i;
        }

        return -1;
    }
};
