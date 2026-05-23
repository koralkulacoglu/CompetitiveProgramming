class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int zeros = count(nums.begin(), nums.end(), 0);
        for (int i=n-1; i>=0; i--) {
            if (zeros == 0) break;
            int val = nums[i];
            if (val == 0) {
                zeros--;
                continue;
            }
            ans++;
            zeros--;
        }
        return ans;
    }
};
