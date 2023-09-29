// brute force

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        long long ans = 0;
        int n = maxHeights.size();
        for (int i=0; i<n; i++) {
            long long cur = maxHeights[i];
            int mx = maxHeights[i];
            for (int j=i+1; j<n; j++) {
                mx = min(mx, maxHeights[j]);
                cur += mx;
            }

            mx = maxHeights[i];
            for (int j=i-1; j>=0; j--) {
                mx = min(mx, maxHeights[j]);
                cur += mx;
            }
            
            ans = max(ans, cur);
        }
        
        return ans;
    }
};
