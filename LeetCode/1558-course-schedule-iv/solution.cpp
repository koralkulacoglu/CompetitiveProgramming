class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(numCourses);
        for (vector<int>& i : prerequisites) graph[i[0]].push_back(i[1]);

        int t = 0;
        vector<bitset<100>> isPrereq(numCourses);
        vector<bool> seen(numCourses, false);

        auto dfs = [&](auto&& self, int node) -> void {
            seen[node] = true;
            for (int neigh : graph[node]) {
                if (!seen[neigh]) self(self, neigh);
                isPrereq[node] |= isPrereq[neigh];
                isPrereq[node].set(neigh);
            }
        };

        for (int i=0; i<numCourses; i++) if (!seen[i]) dfs(dfs, i);

        vector<bool> res;
        for (vector<int>& q : queries) res.push_back(isPrereq[q[0]].test(q[1]));

        return res;
    }
};
