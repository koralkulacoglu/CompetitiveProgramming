class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> vals(n);
        for (int i=0; i<n; i++) vals[i].first = i;

        int m = roads.size();
        for (int i=0; i<m; i++) {
            vals[roads[i][0]].second++;
            vals[roads[i][1]].second++;
        }
        
        sort(vals.begin(), vals.end(),
             [](pair<int, int> const& a, pair<int, int> const& b) {
             return a.second > b.second;
        });
        
        // for (auto i : vals) cout << i.first << ' ' << i.second << '\n';
        // cout << '\n';
        
        long long ans=0;
        long long sv = n;
        for (auto &i : vals) {
            ans += sv * i.second;
            sv--;
        }
        
        return ans;
    }
};
