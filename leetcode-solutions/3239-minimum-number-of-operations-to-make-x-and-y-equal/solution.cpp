class Solution {
public:
    map<int, int> seen;
    int dfs(int x, int y) {
        if (y >= x) return y-x;
        if (seen[x]) return seen[x];

        int res = x-y;
        res = min(res, x%11 + 1 + dfs(x/11, y));
        res = min(res, 11 - x%11 + 1 + dfs(x/11+1, y));
        res = min(res, x%5 + 1 + dfs(x/5, y));
        res = min(res, 5 - x%5 + 1 + dfs(x/5+1, y));
        seen[x] = res;
        return res;
    }
    
    int minimumOperationsToMakeEqual(int x, int y) {
        if (x == y) return 0;
        seen.clear();
        return dfs(x, y);
    }
};
