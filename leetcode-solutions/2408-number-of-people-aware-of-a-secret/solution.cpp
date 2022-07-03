class Solution {
public:
    int MOD = 1e9 + 7;    
    int peopleAwareOfSecret(int n, int delay, int forget) {
        unordered_map<int, long long> freq;
        freq[0] = 1;
        for (int i=0; i<n-1; i++) {
            for (int j=forget-1; j>0; j--) {
                freq[j] = freq[j-1];
                freq[j] %= MOD;
            }
            freq[0] = 0;
            for (int j=1; j<forget; j++) {
                if (j >= delay) {
                    freq[0] += freq[j];
                    freq[0] %= MOD;
                }
            }
        }
        
        long long ans=0;
        for (auto i : freq) {
            ans += i.second;
            ans %= MOD;
        }
        return ans;
    }
};
