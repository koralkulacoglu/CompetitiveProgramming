class Solution {
public:
    // all set bits
    int maximumXOR(vector<int>& nums) {
        int val = 0;
        for (int i : nums) val |= i;
        return val;
    }
};
