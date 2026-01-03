class Solution {
public:
    // size of each component multiplied
    unordered_map<int, bool> seen;
    unordered_map<int, vector<int>> graph;
    int dfs(int node, int size) {
        size++;
        seen[node] = true;
        for (int neigh : graph[node]) {
            if (!seen[neigh]) {
                size += dfs(neigh, 0);
            }
        }
        
        return size;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        seen.clear();
        graph.clear();
        vector<int> sizes;
        for (vector<int> i : edges) {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        for (int i=0; i<n; i++) {
            if (!seen[i]) {
                sizes.push_back(dfs(i, 0));
            }
        }
        long long all = accumulate(sizes.begin(), sizes.end(), 0);
        long long ans=0;
        for (int i : sizes) {
            ans += (all-i)*i;
            // cout << i << ' ';
        }
        return ans/2;
    }
};
