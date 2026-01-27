class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int, int>>> mp;
        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            mp[u].push_back({v, w});
            mp[v].push_back({u, w * 2});
        }

        vector<int> dist(n, 1e9);
        dist[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        while (!pq.empty()) {
            pair<int, int> best = pq.top();
            pq.pop();

            int cost = best.first;
            int node = best.second;

            if (cost > dist[node]) continue;

            for (pair<int, int> neigh : mp[node]) {
                int newNode = neigh.first;
                int newCost = cost + neigh.second;

                if (newCost >= dist[newNode]) continue;

                dist[newNode] = newCost;
                pq.push({newCost, newNode});
            }
        }

        return (dist[n-1] == 1e9 ? -1 : dist[n-1]);
    }
};
