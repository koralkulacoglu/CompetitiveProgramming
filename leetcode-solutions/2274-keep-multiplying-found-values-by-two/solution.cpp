class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int, int> freq;
        for (int &i : nums) freq[i]++;
        while (freq[original]) {
            freq[original]--;
            original *= 2;
            if (!freq[original]) return original;
            freq[original]++;
        }
        return original;
    }
};
