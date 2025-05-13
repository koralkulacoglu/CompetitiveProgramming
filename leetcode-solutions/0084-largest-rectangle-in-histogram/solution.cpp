class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n = heights.size();
        int ans = 0;
        stack<int> stk;
        for (int i=0; i<n; i++) {
            while (!stk.empty() && heights[i] < heights[stk.top()]) {
                int height = heights[stk.top()];
                stk.pop();
                int width = stk.empty() ? i : i - stk.top() - 1;

                ans = max(ans, width * height);
            }
            stk.push(i);
        }

        return ans;
    }
};
