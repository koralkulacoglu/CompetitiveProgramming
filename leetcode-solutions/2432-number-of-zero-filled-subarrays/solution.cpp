class Solution {
public:
    long long zeroFilledSubarray(vector<int>& a) {
        long long n=a.size(), zer=0, ans=0;
        for (int i=0; i<n; i++) {
            if (a[i] == 0) {
                zer++;
                ans += zer;
            }
            else {
                zer = 0;
            }
        }
        return ans;
    }
};
