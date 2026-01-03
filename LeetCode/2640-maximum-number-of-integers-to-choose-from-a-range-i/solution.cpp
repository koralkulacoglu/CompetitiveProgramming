class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        map<int, bool> ban;
        for (int i : banned) ban[i] = true;
        
        int ans = 0;
        int sm = 0;
        for (int i=1; i<=n; i++) {
            if (!ban[i] && sm+i <= maxSum) {
                sm += i;
                ans++;
            }
        }
        return ans;
    }
};
