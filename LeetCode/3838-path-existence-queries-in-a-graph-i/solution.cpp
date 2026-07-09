struct DSU {
    int n;
    vector<int> parent;
    vector<int> size;

    DSU(int n) : n(n), parent(n), size(n, 1) {
        for (int i{0}; i<n; i++) {
            parent[i] = i;
        }
    }

    int find_parent(int x) {
        return parent[x] == x ? x : (parent[x] = find_parent(parent[x]));
    }

    void unite(int x, int y) {
        int parent_x = find_parent(x);
        int parent_y = find_parent(y);

        if (parent_x == parent_y) return;

        int size_x = parent[parent_x];
        int size_y = parent[parent_y];

        if (size_x > size_y) parent[y] = parent_x;
        else parent[x] = parent_y;

        size[x] += size_y;
        size[y] += size_x;
    }

    bool connected(int x, int y) {
        return find_parent(x) == find_parent(y);
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DSU dsu(n);

        for (int i=1; i<n; i++) {
            int prev_num = nums[i-1];
            int cur_num = nums[i];
            int diff = cur_num - prev_num;

            if (diff > maxDiff) continue;

            dsu.unite(i, i-1);
        }

        vector<bool> res;
        for (auto& query : queries) {
            int u = query[0];
            int v = query[1];

            bool con = dsu.connected(u, v);
            res.push_back(con);
        }

        return res;
    }
};
