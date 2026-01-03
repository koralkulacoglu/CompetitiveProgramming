class Solution {
public:
    bool canCross(vector<int>& stones) {
        if (stones[1] != 1) return false;
        int n = stones.size();

        vector<set<int>> dp(n);
        dp[1].insert(1);
        for (int i=2; i<n; i++) {
            for (int j=1; j<i; j++) {
                int k = stones[i] - stones[j]; // jump size
                if (dp[j].find(k) != dp[j].end() || dp[j].find(k-1) != dp[j].end() || dp[j].find(k+1) != dp[j].end()) dp[i].insert(k);
            }
        }

        return !dp[n-1].empty();
    }
};
