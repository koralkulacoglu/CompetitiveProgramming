class Solution {
    int ans;
    unordered_map<int, vector<int>> tree;
    string vals;

    // max val of every char
    pair<char, int> dfs(int node) {
        char val = vals[node];

        int best(-1e9), secBest(-1e9);
        pair<char, int> retVal = {val, 1};
        for (int neigh : tree[node]) {
            pair<char, int> curVal = dfs(neigh);
            char c = curVal.first;
            int score = curVal.second;

            if (c == val) continue;

            retVal.second = max(retVal.second, score + 1);

            if (score >= best) {
                secBest = best;
                best = score;
            }
            else secBest = max(secBest, score);
        }

        ans = max(ans, retVal.second);
        ans = max(ans, best + secBest + 1);

        return retVal;
    }

public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();

        ans = 0;
        vals = s;
        tree.clear();
        for (int i=1; i<n; i++) tree[parent[i]].push_back(i);

        dfs(0);

        return ans;
    }
};

