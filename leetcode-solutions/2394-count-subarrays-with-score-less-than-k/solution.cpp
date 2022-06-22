class Solution {
public:
    // has to be O(n) since nums.lenght is big
    // if up to nums[i] works, nums[0:i] must also work
    // if it does not work, divide the first element of the array until <= k??
    //      this should work
    //      keep track of the sum, and maybe i, j
    //      ans += (i-j+1) for each working i
    long long countSubarrays(vector<int>& a, long long k) {
        int n=a.size(), j=0;
        long long ans=0, sum=0;
        for (int i=0; i<n; i++) {
            sum += a[i];
            if (sum*(i-j+1) < k) {
                ans += i-j+1;
            }
            else {
                // ans should increase here
                while (sum*(i-j+1) >= k) {
                    sum -= a[j];
                    j++;
                }
                ans += i-j+1;
            }
            // cout << i << ' ' << j << '\n';
        }
        return ans;
    }
};
