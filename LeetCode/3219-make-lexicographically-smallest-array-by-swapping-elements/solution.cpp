class Solution {
    struct DSU {
        int n;
        vector<int> parent, size;

        DSU(int n) : n(n), parent(n), size(n, 1) {
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int x) {
            return (x == parent[x] ? x : parent[x] = find(parent[x]));
        }

        void unite(int x, int y) {
            int px = find(x);
            int py = find(y);

            if (px == py) return;
            if (size[px] < size[py]) swap(px, py);

            parent[py] = px;
            size[px] += size[py];
        }
    };

public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        set<pair<int, int>> seen;
        DSU dsu(n);
        for (int i=0; i<n; i++) {
            auto it = seen.lower_bound({nums[i], i});

            if (it != seen.end()) {
                int val = it->first;
                int idx = it->second;

                if (abs(val - nums[i]) <= limit) {
                    dsu.unite(i, idx);
                }
            }

            if (it != seen.begin()) {
                it--;
                int val = it->first;
                int idx = it->second;

                if (abs(val - nums[i]) <= limit) {
                    dsu.unite(i, idx);
                }
            }

            seen.insert({nums[i], i});
        }

        vector<vector<int>> groups(n);
        for (int i=0; i<n; i++) groups[dsu.find(i)].push_back(i);

        vector<int> res(n);
        for (int g = 0; g < n; g++) {
            auto& idxs = groups[g];
            int m = idxs.size();
            if (m == 0) continue;
            
            vector<int> vals;
            for (int i : idxs) vals.push_back(nums[i]);
            sort(vals.begin(), vals.end());

            for (int k=0; k<m; k++) res[idxs[k]] = vals[k];
        }
        
        return res;
    }
};

