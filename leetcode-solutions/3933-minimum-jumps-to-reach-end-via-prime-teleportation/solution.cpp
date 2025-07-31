vector<int> spf;
vector<bool> isPrimeTable;

void sieveSPF(int N) {
    spf.resize(N + 1);
    for (int i = 2; i <= N; i++) spf[i] = i;
    for (int i = 2; i * i <= N; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= N; j += i)
                if (spf[j] == j) spf[j] = i;
        }
    }
}

void sieve(int maxVal) {
    isPrimeTable.assign(maxVal + 1, true);
    isPrimeTable[0] = isPrimeTable[1] = false;
    
    for (int i = 2; i * i <= maxVal; i++) {
        if (isPrimeTable[i]) {
            for (int j = i * i; j <= maxVal; j += i) {
                isPrimeTable[j] = false;
            }
        }
    }
}

vector<int> getPrimeFactors(int x) {
    vector<int> factors;
    while (x > 1) {
        int p = spf[x];
        factors.push_back(p);
        while (x % p == 0) x /= p; 
    }
    return factors;
}

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}


bool pre = false;

class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        
        if (!pre) {
            sieveSPF(1e6+1);
            sieve(1e6+1);
            pre = true;
        }

        unordered_map<int, set<int>> canJump;
        for (int i=0; i<n; i++) {
            vector<int> factors = getPrimeFactors(nums[i]);
            for (int j : factors) canJump[j].insert(i);
        }

        int steps = 0;
        queue<int> que;
        unordered_map<int, bool> visited;
        unordered_set<int> usedPrimes;
        
        que.push(0);
        visited[0] = true;
        
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                int idx = que.front();
                que.pop();
                
                if (idx == n - 1) return steps;

                if (idx + 1 < n && !visited[idx + 1]) {
                    visited[idx + 1] = true;
                    que.push(idx + 1);
                }
                
                if (idx - 1 >= 0 && !visited[idx - 1]) {
                    visited[idx - 1] = true;
                    que.push(idx - 1);
                }

                if (isPrimeTable[nums[idx]] && usedPrimes.find(nums[idx]) == usedPrimes.end()) {
                    usedPrimes.insert(nums[idx]);

                    for (int newIdx : canJump[nums[idx]]) {
                        if (!visited[newIdx]) {
                            visited[newIdx] = true;
                            que.push(newIdx);
                        }
                    }
                }
            }
            steps++;
        }

        return steps;
    }
};
