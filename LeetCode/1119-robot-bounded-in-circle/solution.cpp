class Solution {
    // [0] = move down 1, [1] = move up 1, [2] = move left 1, [3] = move right 1
    vector<int> dx = {0, -1, 0, 1};
    vector<int> dy = {1, 0, -1, 0};
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, d = 0;
        for (int i=0; i<4; i++) {
            for (char instruction : instructions) {
                if (instruction == 'G') {
                    x += dx[d];
                    y += dy[d];
                }
                else if (instruction == 'L') {
                    d = (d - 1 + 4) % 4;
                }
                else if (instruction == 'R') {
                    d = (d + 1) % 4;
                }
            }
        }

        return (x == 0 && y == 0);
    }
};
