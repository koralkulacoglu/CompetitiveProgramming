class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& costs) {
        int n = nums.size();
        long long cost = 1e18;
        int left=1, right=1e6, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            long long curCost = 0;
            for (int i=0; i<n; i++) {
                curCost += abs((long long)nums[i] - mid) * costs[i];
            }
            long long curCost2 = 0;
            for (int i=0; i<n; i++) {
                curCost2 += abs((long long)nums[i] - (mid+1)) * costs[i];
            }
            
            cost = min(cost, curCost);
            cost = min(cost, curCost2);

            if (curCost < curCost2) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return cost;
    }
};
