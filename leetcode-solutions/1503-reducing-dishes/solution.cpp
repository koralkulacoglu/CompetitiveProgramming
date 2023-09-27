class Solution {
public:
    int maxSatisfaction(vector<int>& a) {
        sort(a.begin(), a.end());

        int n = a.size();
        int ans = 0;
        for (int i=0; i<n; i++) {
            int cur = 0;
            for (int j=i; j<n; j++) {
                cur += a[j]*(j-i+1);
            }
            ans = max(ans, cur);
        }

        return ans;
    }
};
