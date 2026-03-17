class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int i : nums) freq[i]++;
        for (int i : nums) {
            if (i%2 == 0 && freq[i] == 1) return i;
        }
        return -1;
    }
};
