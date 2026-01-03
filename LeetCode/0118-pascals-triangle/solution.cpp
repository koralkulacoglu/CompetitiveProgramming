class Solution {
public:
    vector<vector<int>> a;
    vector<vector<int>> generate(int numRows) {
        if (a.empty()) {
            a.push_back({1});
            a.push_back({1, 1});
            for (int i=2; i<=30; i++) {
                a.push_back({1});
                for (int j=0; j<i-1; j++) {
                    a[a.size()-1].push_back(a[a.size()-2][j] + a[a.size()-2][j+1]);
                }
                a[a.size()-1].push_back(1);
            }
        }

        vector<vector<int>> res(a.begin(), a.begin() + numRows);

        return res;
    }
};
