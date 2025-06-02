class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> ans(n, 1);
        for (int i=1; i<n; i++) ans[i] = ratings[i] > ratings[i-1] ? ans[i-1] + 1 : 1;
        for (int i=n-2; i>=0; i--) ans[i] = ratings[i] > ratings[i + 1] ? max(ans[i], ans[i+1] + 1) : ans[i];

        return accumulate(ans.begin(), ans.end(), 0);
    }
};

