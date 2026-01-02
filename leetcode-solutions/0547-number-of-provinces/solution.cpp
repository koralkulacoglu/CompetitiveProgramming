struct DSU {
    int n, provinces;
    vector<int> parents, sizes;

    DSU(int n) : n(n), provinces(n), parents(n), sizes(n, 1) {
        for (int i=0; i<n; i++) parents[i] = i;
    };

    int find(int x) {
        return (parents[x] == x ? x : parents[x] = find(parents[x]));
    }

    void connect(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return;

        if (sizes[px] < sizes[py]) swap(x, y);

        parents[py] = px;
        sizes[px] += sizes[py];
        provinces--;
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        DSU dsu(n);

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (isConnected[i][j]) dsu.connect(i, j);
            }
        }

        return dsu.provinces;
    }
};

