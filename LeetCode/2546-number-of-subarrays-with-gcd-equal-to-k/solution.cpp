class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        for (int i=0; i<n; i++) {
            int g = nums[i];
            if (g == k) ans++;
            for (int j=i+1; j<n; j++) {
                g = __gcd(g, nums[j]);
                if (g == k) ans++;
            }
        }
        return ans;
    }
};
