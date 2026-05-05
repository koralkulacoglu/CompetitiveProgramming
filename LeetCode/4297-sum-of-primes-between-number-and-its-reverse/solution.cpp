class Solution {
public:
    int sumOfPrimesInRange(int n) {
        string rs;
        int temp = n;
        while (temp) {
            char cur = '0';
            rs.push_back(cur + temp%10);
            temp /= 10;
        }

        int r = stoi(rs);

        if (n < r) swap(n, r);

        vector<bool> is_prime(n+1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j <= n; j += i)
                    is_prime[j] = false;
            }
        }

        int ans = 0;
        for (int i=r; i<=n; i++) {
            if (is_prime[i]) ans += i;
        }

        return ans;
    }
};
