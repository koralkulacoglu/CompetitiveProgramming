class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto& e : edges) graph[e[0]].push_back({e[1], e[2]});
        vector<vector<int>> costs(n, vector<int>(k+1, 1e9));
        for (int i=1; i<=k; i++) costs[0][i] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q; // cost, node, c
        q.push({0, 0, 1});
        while (!q.empty()) {
            auto [cost, node, c] = q.top();
            q.pop();
            if (cost > costs[node][c]) continue;
            for (auto [newNode, weight] : graph[node]) {
                int newCost = cost + weight;
                int newC = 1 + c * (labels[newNode] == labels[node]);
                if (newC > k) continue;
                if (newCost >= costs[newNode][newC]) continue;
                for (int i=newC; i<=k; i++) costs[newNode][i] = min(costs[newNode][i], newCost);
                q.push({newCost, newNode, newC});
            }
        }
        int ans = *min_element(costs[n-1].begin(), costs[n-1].end());
        return ans < 1e9 ? ans : -1;
    }
};
