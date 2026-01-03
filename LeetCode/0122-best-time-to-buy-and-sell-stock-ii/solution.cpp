class Solution {
public:
    // this isn't even dp lol
    int maxProfit(vector<int>& a) {
        int n=a.size(), ans=0;
        for (int i=0; i<n-1; i++) ans += (a[i+1]>a[i]?a[i+1]-a[i]:0);
        return ans;
    }
};
