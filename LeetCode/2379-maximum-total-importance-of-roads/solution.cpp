class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<int>> graph;

        for (auto& road : roads) {
            graph[road[0]].push_back(road[1]);
            graph[road[1]].push_back(road[0]);
        }

        vector<int> importance(n);
        for (int i=0; i<n; i++) {
            importance[i] = graph[i].size();
        }

        sort(importance.begin(), importance.end());

        long long ans = 0;
        for (int i=0; i<n; i++) {
            long long degree = importance[i];
            ans += degree * (i + 1);
        }

        return ans;
    }
};
