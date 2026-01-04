class Solution {
    bool computed = false;
    vector<pair<int, int>> divisors;

    void precompute(int n) {
        divisors.resize(n+1, {0, 0});

        for (int i=1; i<=n; i++) {
            for (int j=1; i*j<=n; j++) {
                divisors[i*j].first++;
                divisors[i*j].second += i;
            }
        }

        computed = true;
    }

public:
    int sumFourDivisors(vector<int>& nums) {
        if (!computed) precompute(1e5);

        int ans = 0;
        for (int i : nums) {
            if (divisors[i].first == 4) ans += divisors[i].second;
        }

        return ans;
    }
};
