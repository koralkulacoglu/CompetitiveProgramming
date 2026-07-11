class Solution {
    int n = 8;
    int m = 8;
    vector<int> dx = {-1, -1, -1, 1, 1, 1, 0, 0};
    vector<int> dy = {0, -1, 1, 0, 1, -1, -1, 1};
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        if (board[rMove][cMove] != '.') return false;

        char otherColor = (color == 'W' ? 'B' : 'W');

        for (int d=0; d<8; d++) {
            int xDelta = dx[d];
            int yDelta = dy[d];
            int x = rMove + xDelta;
            int y = cMove + yDelta;

            auto valid = [&]() {
                if (x < 0 || x >= n || y < 0 || y >= m) return false;
                return true;
            };

            if (!valid() || board[x][y] != otherColor) continue;

            x += xDelta;
            y += yDelta;

            while (valid()) {
                char col = board[x][y];

                if (col == color) return true;
                else if (col == '.') break;

                x += xDelta;
                y += yDelta;
            }
        }

        return false;
    }
};

