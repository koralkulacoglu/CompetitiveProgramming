class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int j = n-1, ans = 0;
        for (int i=0; i<=j; i++) {
            ans = max(ans, (j-i) * min(height[i], height[j]));
            while (i<=j && height[i] > height[j]) {
                j--;
                ans = max(ans, (j-i) * min(height[i], height[j]));
            }
        }

        return ans;
    }
};
