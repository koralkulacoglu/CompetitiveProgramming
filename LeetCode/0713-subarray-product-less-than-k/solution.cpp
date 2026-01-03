class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int j = 0;
        int ans = 0;
        int prod = 1;
        for (int i=0; i<n; i++) {
            prod *= nums[i];
            while (prod >= k && j <= i) {
                prod /= nums[j];
                j++;
            }
            cout << j << ' ' << i << '\n';
            ans += i-j+1;
        }   
        return ans;
    }
};
