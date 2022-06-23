class Solution {
public:
    // 2 pointer
    int numberOfArithmeticSlices(vector<int>& a) {
        int n=a.size(), ans=0, j=0;
        for (int i=2; i<n; i++) {
            if (a[i]-a[i-1] == a[i-1]-a[i-2]) {
                ans += i-j-1;
            }
            else {
                j = i-1;
            }
        }
        return ans;
    }
};
