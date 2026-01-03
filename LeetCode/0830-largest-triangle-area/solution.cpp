// ½ |x₁(y₂ – y₃) + x₂(y₃ – y₁) + x₃(y₁ – y₂)|

class Solution {
public:
    double area(vector<int> a, vector<int> b, vector<int> c) {
        return double(abs(a[0] * (b[1] - c[1]) + b[0] * (c[1] - a[1]) + c[0] * (a[1] - b[1]))) / 2;
    }

    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0;
        for (auto i : points) {
            for (auto j : points) {
                for (auto k : points) {
                    ans = max(ans, area(i, j, k));
                }
            }
        }
        return ans;
    }
};
