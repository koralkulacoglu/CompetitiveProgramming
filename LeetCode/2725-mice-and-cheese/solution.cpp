class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        vector<pair<int, int>> reward(n);
        for (int i=0; i<n; i++) reward[i] = {reward1[i], reward2[i]};
        sort(reward.begin(), reward.end(), [](pair<int, int> a, pair<int, int> b) {
            int aVal = a.first - a.second;
            int bVal = b.first - b.second;
            return aVal > bVal;
        });
        int ans = 0;
        for (int i=0; i<k; i++) ans += reward[i].first;
        for (int i=k; i<n; i++) ans += reward[i].second;
        return ans;
    }
};

