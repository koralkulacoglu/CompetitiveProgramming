class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> stk;
        vector<int> res(n, -1);
        for (int i=0; i<2*n; i++) {
            int num = nums[i%n];
            while (!stk.empty() && nums[stk.top()] < num) {
                res[stk.top()] = num;
                stk.pop();
            }
            if (i < n) stk.push(i);
        }
        return res;
    }
};
