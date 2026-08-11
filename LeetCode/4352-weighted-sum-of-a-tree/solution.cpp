class Solution {
    int n, h;
    unordered_map<int, vector<int>> tree;
    vector<int> vals;
    
    int getHeight(int node, int height=1) {
        int maxHeight = height;

        for (int neigh : tree[node]) {
            maxHeight = max(maxHeight, getHeight(neigh, height+1));
        }

        return maxHeight;
    }

    long long dfs(int node, long long d=1) {
        long long ans = vals[node] * (h - d + 1);

        for (int neigh : tree[node]) {
            ans += dfs(neigh, d+1);
        }

        return ans;
    }
    
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        n = parent.size();
        tree.clear();
        vals = nums;
        for (int i=1; i<n; i++) tree[parent[i]].push_back(i);

        h = getHeight(0);

        return dfs(0);
    }
};
