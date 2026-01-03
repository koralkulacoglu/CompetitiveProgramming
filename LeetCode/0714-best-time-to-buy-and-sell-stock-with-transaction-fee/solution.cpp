class Solution {
public:
    int maxProfit(vector<int>& a, int fee) {
        int n = a.size();
        int hold = -a[0];
        int cash = 0;
        for(int i=0;i<n;i++){
            cash = max(cash, hold + a[i] - fee);
            hold = max(hold, cash - a[i]);
        }
        return cash;
    }
};
