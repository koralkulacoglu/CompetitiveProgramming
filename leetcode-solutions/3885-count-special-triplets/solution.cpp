class Solution {
    int MOD = 1e9+7;
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> freq, freq2;
        for (int i : nums) {
            if (i%2 == 0) {
                ans += freq2[i/2];
                ans %= MOD;
            }
            freq2[i] += freq[i*2];
            freq2[i] %= MOD;
            freq[i]++;
        }

        return ans;
    }
};
