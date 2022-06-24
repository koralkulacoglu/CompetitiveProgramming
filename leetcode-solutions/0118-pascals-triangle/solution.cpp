class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> a;
        a.push_back({1});
        if (numRows == 1) return a;
        a.push_back({1, 1});
        for (int i=2; i<numRows; i++) {
            a.push_back({});
            a[i].push_back(1);
            for (int j=0; j<i-1; j++) {
                a[i].push_back(a[i-1][j] + a[i-1][j+1]);
            }
            a[i].push_back(1);
        }
        return a;
    }
};
