class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int i : nums) freq[i]++;
        unordered_map<int, int> freqB;
        for (auto i : freq) freqB[i.second]++;
        for (int i : nums) {
            if (freqB[freq[i]] == 1) return i;
        }
        return -1;
    }
};
