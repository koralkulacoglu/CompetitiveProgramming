class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        priority_queue<pair<int, int>> pq;
        for (int i=0; i<k; i++) pq.emplace(nums[i], i);
        res.push_back(pq.top().first);
        for (int i=k; i<n; i++) {
            pq.emplace(nums[i], i);
            while (i - pq.top().second >= k) pq.pop();
            res.push_back(pq.top().first);
        }
        return res;
    }
};
