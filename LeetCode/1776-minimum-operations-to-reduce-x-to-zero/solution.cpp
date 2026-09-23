class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> psa(n+1, 0);
        for (int i=1; i<=n; i++) psa[i] = psa[i-1] + nums[i-1];
        unordered_map<int, int> psaMap;
        for (int i=0; i<=n; i++) psaMap[psa[i]] = i;
        int ans = psaMap.contains(x) ? psaMap[x] : 1e9;
        int ops = 0;
        for (int i=n-1; i>=0; i--) {
            x -= nums[i];
            ops++;
            if (psaMap.contains(x)) ans = min(ans, ops + psaMap[x]);
        }
        return ans <= n ? ans : -1;
    }
};
