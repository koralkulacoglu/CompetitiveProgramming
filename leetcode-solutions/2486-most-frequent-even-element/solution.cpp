class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> freq;
        for (int i : nums) {
            if (i%2 == 0) {
                freq[i]++;
            }
        }
        int ans=-1, mx=0;
        for (auto i : freq) {
            if (i.second > mx) {
                ans = i.first;
                mx = i.second;
            }
            else if (i.second == mx && i.first < ans) {
                ans = i.first;
            }
        }
        return ans;
    }
};
