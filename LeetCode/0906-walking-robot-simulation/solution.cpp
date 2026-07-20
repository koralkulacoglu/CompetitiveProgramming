class Solution {
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> obs;

        for (auto& o : obstacles) {
            obs.emplace(o[0], o[1]);
        }

        auto dist = [](int x, int y) {
            return x*x + y*y;
        };

        auto isValid = [&](int a, int b) {
            return obs.find(make_pair(a, b)) == obs.end();
        };

        int d = 0;

        auto turnLeft = [&]() {
            d--;
            if (d == -1) d = 3;
        };

        auto turnRight = [&]() {
            d++;
            if (d == 4) d = 0;
        };

        int x = 0, y = 0;
        int ans = 0;
        for (int cmd : commands) {
            if (cmd == -2) {
                turnLeft();
            }
            else if (cmd == -1) {
                turnRight();
            }
            else {
                for (int i=0; i<cmd; i++) {
                    int nx = x + dir[d].first;
                    int ny = y + dir[d].second;

                    if (isValid(nx, ny)) {
                        x = nx;
                        y = ny;
                        ans = max(ans, dist(x, y));
                    }
                }
            }
            // cout << x << ' ' << y << ' ' << d << endl;
        }

        return ans;
    }
};
