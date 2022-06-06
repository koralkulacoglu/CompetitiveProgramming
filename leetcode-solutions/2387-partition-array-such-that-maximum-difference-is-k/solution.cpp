class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n=nums.size(), mx=0, mn=1e9, ans=1;
        for (int &i : nums) {
            mx = max(mx, i);
            mn = min(mn, i);
            if (mx-mn > k) {
                ans++;
                mn = i;
                mx = i;
            }
        }
        return ans;
    }
};
