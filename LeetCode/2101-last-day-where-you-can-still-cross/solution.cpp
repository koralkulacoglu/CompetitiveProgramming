struct DSU {
	vector<int> parents, sizes;

	DSU(int n=2e5) : parents(n), sizes(n, 1) {
		for (int i=0; i<n; i++) parents[i] = i;
	}

	int find(int x) {
		return parents[x] == x ? x : (parents[x] = find(parents[x]));
	}

	bool unite(int x, int y) {
		int x_root = find(x);
		int y_root = find(y);
		if (x_root == y_root) return false;

		if (sizes[x_root] < sizes[y_root]) swap(x_root, y_root);
		sizes[x_root] += sizes[y_root];
		parents[y_root] = x_root;

		return true;
	}

	bool connected(int x, int y) {
		return find(x) == find(y);
	}
};

class Solution {
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<bool>> matrix(row+2, vector<bool>(col, true));
        DSU dsu((row+2) * col);

        auto getCoord = [&](int x, int y) {
            return x * col + y;
        };

        auto isValid = [&](int x, int y) {
            if (x < 0 || x >= row+2 || y < 0 || y >= col) return false;
            return true;
        };

        for (int j = 0; j < col; j++) {
            matrix[0][j] = false;
            matrix[row+1][j] = false;
            if (j > 0) {
                dsu.unite(getCoord(0, j), getCoord(0, j - 1));
                dsu.unite(getCoord(row + 1, j), getCoord(row + 1, j - 1));
            }
        }

        int day = cells.size();

        reverse(cells.begin(), cells.end());

        for (vector<int>& cell : cells) {
            day--;
            int x = cell[0];
            int y = cell[1]-1;
            matrix[x][y] = false;
            for (int i=0; i<4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if (!isValid(newX, newY)) continue;

                if (!matrix[newX][newY]) dsu.unite(getCoord(x, y), getCoord(newX, newY));
            }

            if (dsu.connected(getCoord(0, 0), getCoord(row+1, 0))) return day;
        }

        return 0;
    }
};

