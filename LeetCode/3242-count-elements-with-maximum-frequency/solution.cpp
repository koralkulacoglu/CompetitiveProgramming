class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(100);
        int mx = 0;
        for (int i : nums) {
            freq[i-1]++;
            mx = max(mx, freq[i-1]);
        }

        int ans = 0;
        for (int i : freq) {
            if (i == mx) ans += i;
        }

        return ans;
    }
};
