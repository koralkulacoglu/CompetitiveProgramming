class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        auto neighbor = [](const string& a, const string& b) {
            bool d = false;
            int n = a.size();
            for (int i = 0; i < n; i++) {
                if (a[i] != b[i]) {
                    if (d) return false;
                    d = true;
                }
            }
            return d;
        };

        wordList.erase(remove(wordList.begin(), wordList.end(), beginWord), wordList.end());
        wordList.insert(wordList.begin(), beginWord);

        int n = wordList.size();

        int endIdx = -1;
        for (int i = 1; i < n; i++) {
            if (wordList[i] == endWord) { endIdx = i; break; }
        }
        if (endIdx == -1) return {};

        unordered_map<int, unordered_set<int>> neigh;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (neighbor(wordList[i], wordList[j])) {
                    neigh[i].insert(j);
                    neigh[j].insert(i);
                }
            }
        }

        vector<int> minDist(n, INT_MAX);
        vector<vector<int>> from(n);
        queue<int> q;
        q.push(0);
        minDist[0] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            int newDist = minDist[node] + 1;

            for (int nb : neigh[node]) {
                if (minDist[nb] < newDist) continue;
                if (minDist[nb] != newDist) q.push(nb);
                minDist[nb] = newDist;
                from[nb].push_back(node);
            }
        }

        if (minDist[endIdx] == INT_MAX) return {};

        vector<vector<string>> res;
        vector<string> path;

        function<void(int)> dfs = [&](int node) {
            path.push_back(wordList[node]);
            if (node == 0) {
                res.push_back(vector<string>(path.rbegin(), path.rend()));
            } else {
                for (int p : from[node]) dfs(p);
            }
            path.pop_back();
        };

        dfs(endIdx);
        return res;
    }
};
