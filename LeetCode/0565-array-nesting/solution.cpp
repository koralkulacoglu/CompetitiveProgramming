class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i=0; i<n; i++) {
            if (nums[i] == -1) continue;
            int x = i;
            int cur = 0;
            while (nums[x] != -1) {
                int px = x;
                x = nums[x];
                nums[px] = -1;
                cur++;
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};
