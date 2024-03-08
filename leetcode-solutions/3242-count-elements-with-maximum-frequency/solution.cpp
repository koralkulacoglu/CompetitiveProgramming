class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int> freq;
        for (int i : nums) freq[i]++;
        int mx = -1e9;
        for (auto i : freq) mx = max(i.second, mx);
        int ans = 0;
        for (auto i : freq) {
            if (i.second == mx) ans += mx;
        }
        return ans;
    }
};
