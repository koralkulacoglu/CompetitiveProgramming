class Solution {
public:
    int waysToSplitArray(vector<int>& a) {
        int n=a.size();
        vector<long long> psa(n);
        psa[n-1] = a[n-1];
        for (int i=n-2; i>=0; i--) psa[i] = psa[i+1] + a[i];
        
        int ans=0;
        long long sum=0;
        for (int i=0; i<n-1; i++) {
            sum += a[i];
            if (sum >= psa[i+1]) {
                ans++;
            }
        }
        
        return ans;
    }
};
