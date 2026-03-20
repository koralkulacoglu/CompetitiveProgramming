// shortest path from src1 and src2 to a 'meeting point' and SP from dest to any 'meeting point'

class Solution {
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& e : edges) graph[e[0]].push_back({e[1], e[2]});

        auto bfs = [&](int start) {
            vector<long long> costs(n, 1e18);
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
            pq.push({0, start});
            costs[start] = 0;
            while (!pq.empty()) {
                auto [cost, node] = pq.top();
                pq.pop();
    
                if (cost > costs[node]) continue;

                for (auto& neigh : graph[node]) {
                    int newNode = neigh.first;
                    long long newCost = cost + neigh.second;

                    if (newCost < costs[newNode]) {
                        costs[newNode] = newCost;
                        pq.push({newCost, newNode});
                    }
                }
            }
            return costs;
        };

        vector<long long> src1Costs = bfs(src1);
        vector<long long> src2Costs = bfs(src2);

        vector<vector<pair<int, int>>> graphR(n);
        for (int i=0; i<n; i++) {
            for (auto& e : graph[i]) {
                graphR[e.first].push_back({i, e.second});
            }
        }
        graph = graphR;

        vector<long long> destCosts = bfs(dest);

        long long ans = 1e18;
        for (int i=0; i<n; i++) ans = min(ans, src1Costs[i] + src2Costs[i] + destCosts[i]);

        return ans < 1e18 ? ans : -1;
    }
};
