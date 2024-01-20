class Solution {
public:
    bool IsBitSet(int num, int bit) {
        return 1 == ( (num >> bit) & 1);
    }
    
    int minOperations(vector<int>& nums, int k) {
        int x=0, ans=0;
        for (int i : nums) x ^= i;
        for (int i=0; i<31; i++) {
            ans += IsBitSet(k, i) != IsBitSet(x, i);
        }
        return ans;
    }
};
