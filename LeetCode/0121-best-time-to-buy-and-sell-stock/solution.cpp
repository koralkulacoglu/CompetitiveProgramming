class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0, mn=1e9;
        for (int &i : prices) {
            ans = max(ans, i-mn);
            mn = min(mn, i);
        }
        return ans;
    }
};
