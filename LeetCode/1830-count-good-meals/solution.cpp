class Solution {
    int MOD = 1e9 + 7;
public:
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int, int> freq;
        int ans = 0;
        for (int d : deliciousness) {
            for (int i=0; i<22; i++) {
                ans += freq[(1 << i) - d];
                ans %= MOD;
            }
            freq[d]++;
        }
        return ans;
    }
};
