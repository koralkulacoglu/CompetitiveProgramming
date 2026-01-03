class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long ans = 1;
        int streak = 1;
        for (int i=1; i<n; i++) {
            if (prices[i] == prices[i-1]-1) streak++;
            else streak = 1;
            ans += streak;
        }
        return ans;
    }
};
