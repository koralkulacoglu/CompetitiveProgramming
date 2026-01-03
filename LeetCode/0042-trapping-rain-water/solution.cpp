class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        stack<int> barIdxs;
        for (int i=0; i<n; i++) {
            while (!barIdxs.empty() && height[i] > height[barIdxs.top()]) {
                int topIdx = barIdxs.top(); barIdxs.pop();
                if (barIdxs.empty()) break;
                
                int leftIdx = barIdxs.top();
                int totalWidth = i - leftIdx - 1;

                int totalHeight = min(height[i], height[leftIdx]) - height[topIdx];
                ans += totalHeight * totalWidth;
            }
            barIdxs.push(i);
        }
        return ans;
    }
};
