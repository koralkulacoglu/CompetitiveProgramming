class Solution {
public:
    long long minCost(string s, int encCost, int flatCost) {
        int n = s.size();
        
        vector<int> psa(n+1, 0);
        for (int i=0; i<n; i++) psa[i+1] = psa[i] + (s[i] == '1'? 1 : 0);

        auto solve = [&](auto& self, int l, int r) -> long long {
            long long len = r - l + 1;
            long long ones = psa[r+1] - psa[l];
            long long cost = (ones == 0) ? flatCost : len * ones * encCost;

            if (len%2 == 0) {
                int mid = l + len / 2 - 1;
                long long splitCost = self(self, l, mid) + self(self, mid+1, r);
                cost = min(cost, splitCost);
            }

            return cost;
        };

        return solve(solve, 0, n-1);
    }
};
