class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> vals;
        for (int i=1; i<=n; i++) {
            vals.push_back(to_string(i));
        }
        sort(vals.begin(), vals.end());
        vector<int> res;
        for (string i : vals) res.push_back(stoi(i));
        return res;
    }
};
