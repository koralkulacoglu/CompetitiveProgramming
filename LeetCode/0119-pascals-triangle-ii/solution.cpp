class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> a;
        a.push_back({1});
        if (rowIndex == 0) return {1};
        a.push_back({1, 1});
        for (int i=2; i<=rowIndex; i++) {
            a.push_back({});
            a[i].push_back(1);
            for (int j=0; j<i-1; j++) {
                a[i].push_back(a[i-1][j] + a[i-1][j+1]);
            }
            a[i].push_back(1);
        }
        return a[a.size()-1];

    }
};
