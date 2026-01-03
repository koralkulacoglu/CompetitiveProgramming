class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        int n = s.size();
        vector<long long> costs(26, 0);
        for (int i=0; i<n; i++) costs[s[i]-'a'] += cost[i];

        long long total = accumulate(costs.begin(), costs.end(), 0LL);
        long long maxCost = *max_element(costs.begin(), costs.end());

        return total - maxCost;
    }
};
