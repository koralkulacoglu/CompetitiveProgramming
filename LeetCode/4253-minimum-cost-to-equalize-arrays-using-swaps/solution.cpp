class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq1, freq2, freq;
        for (int i : nums1) {
            freq1[i]++;
            freq[i]++;
        }
        for (int i : nums2) {
            freq2[i]++;
            freq[i]++;
        }

        int ans = 0;
        for (auto i : freq) {
            if (i.second%2) return -1;
            int f1 = freq1[i.first];
            int f2 = freq2[i.first];
            ans += abs(f1 - f2);
        }

        return ans / 4;
    }
};
