class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        deque<int> window;
        for (int i=0; i<n; i++) {
            while (!window.empty() && nums[i] >= nums[window.front()]) window.pop_front();
            window.push_front(i);
            while (!window.empty() && i - window.back() + 1 > k) window.pop_back();
            if (i >= k-1) res.push_back(nums[window.back()]);
        }
        return res;
    }
};
