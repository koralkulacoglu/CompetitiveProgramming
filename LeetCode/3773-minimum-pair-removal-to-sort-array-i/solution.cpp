class Solution {
    bool decreasing(vector<int>& nums) {
        int n = nums.size();
        for (int i=1; i<n; i++) {
            if (nums[i] < nums[i-1]) return false;
        }
        return true;
    }

public:
    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;
        while (!decreasing(nums)) {
            ans++;
            int n = nums.size();
            int idx = 1;
            for (int i=2; i<n; i++) {
                int newSum = nums[i] + nums[i-1];
                int bestSum = nums[idx] + nums[idx-1];
                if (newSum < bestSum) idx = i;
            }

            int sum = nums[idx] + nums[idx-1];
            nums.erase(nums.begin() + idx);
            nums[idx-1] = sum;
        }

        return ans;
    }
};
