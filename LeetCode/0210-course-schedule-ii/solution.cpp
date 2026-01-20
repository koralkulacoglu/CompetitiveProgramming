class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        
        for (vector<int>& prereq : prerequisites) {
            adj[prereq[1]].push_back(prereq[0]);
            indegree[prereq[0]]++;
        }

        queue<int> que;
        vector<int> res;
        
        for (int i=0; i<numCourses; i++) {
            if (indegree[i] == 0) {
                que.push(i);
            }
        }

        while (!que.empty()) {
            int course = que.front();
            que.pop();
            res.push_back(course);

            for (int neigh : adj[course]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0) {
                    que.push(neigh);
                }
            }
        }

        if (res.size() != numCourses) return {};
        return res;
    }
};

