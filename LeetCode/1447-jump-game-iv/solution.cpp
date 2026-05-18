class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        unordered_map<int, vector<int>> nums;
        unordered_map<int, bool> numsVis;
        for (int i=0; i<n; i++) nums[arr[i]].push_back(i);
        vector<int> dist(n, 1e9);
        dist[0] = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (node < n-1 && dist[node+1] == 1e9) {
                dist[node+1] = dist[node] + 1;
                q.push(node+1);
            }
            if (node > 0 && dist[node-1] == 1e9) {
                dist[node-1] = dist[node] + 1;
                q.push(node-1);
            }
            if (numsVis[arr[node]]) continue;
            for (int neigh : nums[arr[node]]) {
                if (dist[neigh] == 1e9) {
                    dist[neigh] = dist[node] + 1;
                    q.push(neigh);
                }
            }
            numsVis[arr[node]] = true;
        }
        return dist[n-1];
    }
};
