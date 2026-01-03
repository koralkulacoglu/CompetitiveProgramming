class Solution {
public:
    int maximumsSplicedArray(vector<int>& a, vector<int>& b) {
        // dp
        int ans=0, sm=0, n=a.size();
        for (int i=0; i<n; i++) {
            sm = max(0, sm+b[i]-a[i]);
            ans = max(ans, sm);
        }
        int ans2=0, sm2=0;
        for (int i=0; i<n; i++) {
            sm2 = max(0, sm2+a[i]-b[i]);
            ans2 = max(ans2, sm2);
        }
        int res = accumulate(a.begin(), a.end(), 0) + ans;
        res = max(res, accumulate(b.begin(), b.end(), 0) + ans2);
        
        return res;
    }
};
