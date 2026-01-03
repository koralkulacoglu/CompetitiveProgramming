class Solution {
public:
    double calculateTax(vector<vector<int>>& a, int income) {
        double ans=0;
        for (int i=0; i<a.size(); i++) {
            int u = a[i][0];
            double p = a[i][1];
            
            int add = u;
            if (i > 0) add -= a[i-1][0];
            double cnt = min(income, add);
            ans += cnt * p / 100;

            income -= cnt;
            if (income <= 0) break;
        }
        return ans;
    }
};
