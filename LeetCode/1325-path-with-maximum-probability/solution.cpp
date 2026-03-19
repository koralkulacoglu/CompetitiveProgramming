class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        int m = edges.size();
        unordered_map<int, vector<pair<int, double>>> graph;
        for (int i=0; i<m; i++) {
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        vector<double> probs(n, 0);
        priority_queue<pair<double, int>> pq;
        probs[start_node] = 1;
        pq.push({1, start_node});
        while (!pq.empty()) {
            auto [prob, node] = pq.top();
            if (node == end_node) return prob;
            pq.pop();

            if (prob < probs[node]) continue;

            for (auto& neigh : graph[node]) {
                int newNode = neigh.first;
                double newProb = prob * neigh.second;

                if (newProb > probs[newNode]) {
                    probs[newNode] = newProb;
                    pq.push({newProb, newNode});
                }
            }
        }

        return probs[end_node];
    }
};
