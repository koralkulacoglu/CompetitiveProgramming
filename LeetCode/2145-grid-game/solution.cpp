class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> psaB(n); psaB[n-1] = 0;
        for (int i=n-2; i>=0; i--) psaB[i] = psaB[i+1] + grid[0][i+1];
        long long psa = 0;
        long long ans = 1e18;
        for (int i=0; i<n; i++) {
            ans = min(ans, max(psa, psaB[i]));
            psa += grid[1][i];
        }
        return ans;
    }
};
