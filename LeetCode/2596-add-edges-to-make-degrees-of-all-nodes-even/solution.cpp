/*

- >4            (fails, not enough edges)
- 4 odd nodes   (works, connect nodes)
- 3 odd nodes   (fails)
- 2 odd nodes   (works, connect each other)
- 1 odd node    (fails)
- 0 odd nodes   (works)

0: always works

2: (can't be connected, IF connected, find a node that neither is connected to and connect both to that one)

4: (2 pairs must be not connected)


*/

class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        int m = edges.size();

        unordered_map<int, vector<int>> graph;
        unordered_map<int, unordered_map<int, bool>> pairs;

        for (auto& edge : edges) {
            int a = edge[0] - 1;
            int b = edge[1] - 1;
            graph[a].push_back(b);
            graph[b].push_back(a);
            pairs[a][b] = true;
            pairs[b][a] = true;
        }

        vector<int> evens, odds;

        for (int i=0; i<n; i++) {
            if (graph[i].size() % 2 == 0) evens.push_back(i);
            else odds.push_back(i);
        }

        int o = odds.size();

        if (o == 0) return true;

        if (o == 2) {
            int o1 = odds[0];
            int o2 = odds[1];

            bool connected = pairs[o1][o2];

            if (!connected) return true;

            for (int c = 0; c < n; c++) {
                if (c == o1 || c == o2) continue;
                if (!pairs[o1][c] && !pairs[o2][c]) return true;
            }
            return false;
        }

        if (o == 4) {
            int o1 = odds[0];
            int o2 = odds[1];
            int o3 = odds[2];
            int o4 = odds[3];

            if (!pairs[o1][o2] && !pairs[o3][o4]) return true;
            if (!pairs[o1][o3] && !pairs[o2][o4]) return true;
            if (!pairs[o1][o4] && !pairs[o2][o3]) return true;
            return false;
        }

        return false;
    }
};
