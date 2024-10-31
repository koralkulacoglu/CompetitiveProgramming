class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);
        vector<int> result;
        
        // Build adjacency list and in-degree count
        for (const auto& prereq : prerequisites) {
            int course = prereq[0];
            int prereqCourse = prereq[1];
            adj[prereqCourse].push_back(course);
            inDegree[course]++;
        }
        
        // Initialize queue with courses having zero prerequisites
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        // Process the courses in topological order
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            result.push_back(course);
            
            for (int neighbor : adj[course]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // If result size is less than numCourses, there was a cycle
        if (result.size() != numCourses) return {};
        return result;
    }
};
