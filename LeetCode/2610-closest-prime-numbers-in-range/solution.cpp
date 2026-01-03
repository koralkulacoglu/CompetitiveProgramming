class Solution {
public:
    vector<bool> is_prime;

    void calcPrimes(int n=1e6+1) {
        is_prime.resize(n+1, true);
        is_prime[0] = is_prime[1] = false;
    
        for (int p = 2; p * p <= n; ++p) {
            if (is_prime[p]) {
                for (int multiple = p * p; multiple <= n; multiple += p) {
                    is_prime[multiple] = false;
                }
            }
        }
    }

    vector<int> closestPrimes(int left, int right) {
        if (is_prime.empty()) calcPrimes();

        int prev=-1;
        vector<int> primes;
        for (int i=left; i<=right; i++) {
            if (is_prime[i]) {
                if (prev != -1 && (primes.empty() || i - prev < primes[1] - primes[0])) primes = {prev, i};
                prev = i;
            }
        }

        if (primes.empty()) primes = {-1, -1};

        return primes;
    }
};
