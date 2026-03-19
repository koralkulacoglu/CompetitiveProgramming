class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& t : times) graph[t[0]-1].push_back({t[1]-1, t[2]});

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> costs(n, 1e9);
        costs[k-1] = 0;
        pq.push({0, k-1});
        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            if (cost > costs[node]) continue;

            for (auto& neigh : graph[node]) {
                int newNode = neigh.first;
                int newCost = cost + neigh.second;

                if (newCost < costs[newNode]) {
                    costs[newNode] = newCost;
                    pq.push({newCost, newNode});
                }
            }
        }

        int ans = *max_element(costs.begin(), costs.end());

        return (ans < 1e9 ? ans : -1);
    }
};
