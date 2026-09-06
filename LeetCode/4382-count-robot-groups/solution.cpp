class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = position.size();
        int groups = n;
        vector<bool> removed(n, false);
        for (int i=1; i<n; i++) {
            if (position[i] - position[i-1] <= distance) {
                removed[i-1] = true;
                groups--;
            }
        }
        stack<pair<int, int>> robots;
        for (int i=n-1; i>=0; i--) {
            if (removed[i]) continue;
            int curSpeed = speed[i];
            int curPos = position[i];
            while (!robots.empty()) {
                auto [nextSpeed, nextPos] = robots.top();

                if (nextPos - curPos <= distance || nextSpeed < curSpeed) {
                    curSpeed = nextSpeed;
                    curPos = nextPos;
                    groups--;
                    robots.pop();
                }
                else break;
            }
            robots.emplace(curSpeed, curPos);
        }
        return groups;
    }
};
