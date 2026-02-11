class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        auto dist = [&](int x, int y) {
            int cx = center[0];
            int cy = center[1];
            return abs(cx - x) + abs(cy - y);
        };
        
        vector<vector<int>> reach;
        for (vector<int>& tower : towers) {
            int x = tower[0];
            int y = tower[1];
            int q = tower[2];
            if (dist(x, y) > radius) continue;
            reach.push_back({x, y, q});
        }

        if (reach.empty()) return {-1, -1};

        sort(reach.begin(), reach.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[2] > b[2]) return true;
            if (a[2] < b[2]) return false;
            if (a[0] < b[0]) return true;
            if (a[0] > b[0]) return false;
            return a[1] < b[1];
        });

        return {reach[0][0], reach[0][1]};
    }
};
