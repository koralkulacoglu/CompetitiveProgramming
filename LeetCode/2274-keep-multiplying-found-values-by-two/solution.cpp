class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int, bool> seen;
        for (int i : nums) seen[i] = true;
        while (seen[original]) original *= 2;
        return original;
    }
};
