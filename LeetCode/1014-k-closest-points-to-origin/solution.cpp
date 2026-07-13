class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto dist = [](vector<int>& x) -> int {
            return x[0] * x[0] + x[1] * x[1];
        };

        sort(points.begin(), points.end(), [&](auto& a, auto& b) {
            return dist(a) < dist(b);
        });

        vector<vector<int>> res(points.begin(), points.begin() + k);
        
        return res;
    }
};
