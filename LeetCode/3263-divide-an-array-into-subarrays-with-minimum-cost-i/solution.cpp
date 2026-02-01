class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int> pq;
        for (int i=1; i<n; i++) {
            pq.push(nums[i]);
            if (pq.size() > 2) pq.pop();
        }
        int ans = nums[0] + pq.top();
        pq.pop();
        ans += pq.top();
        return ans;
    }
};
