class Solution {
public:
    map<int, vector<int>> mp;
    map<int, int> state;  // 0 = unvisited, 1 = visiting, 2 = visited

    bool hasCycle(int course) {
        if (state[course] == 1) return true;
        if (state[course] == 2) return false;

        state[course] = 1;
        for (int neigh : mp[course]) {
            if (hasCycle(neigh)) return true;
        }
        state[course] = 2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        mp.clear();
        state.clear();

        for (const vector<int>& p : prerequisites) {
            mp[p[1]].push_back(p[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0 && hasCycle(i)) return false;
        }
        return true;
    }
};

