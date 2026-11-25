class Solution {
    unordered_map<long long, int> rollingHash(const vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n || k <= 0) return {};
        const long long BASE = 1000003; 
        const long long MOD = 1000000007; 
        const long long OFFSET = 1000001; 
        unordered_map<long long, int> hashes;
        long long current_hash = 0;
        long long highest_power = 1;
        for (int i = 0; i < k - 1; ++i) {
            highest_power = (highest_power * BASE) % MOD;
        }
        for (int i = 0; i < k; ++i) {
            long long val = nums[i] + OFFSET;
            current_hash = (current_hash * BASE + val) % MOD;
        }
        hashes[current_hash]++;
        for (int i = k; i < n; ++i) {
            long long outgoing = nums[i - k] + OFFSET;
            long long incoming = nums[i] + OFFSET;
            long long term_to_remove = (outgoing * highest_power) % MOD;
            current_hash = (current_hash - term_to_remove + MOD) % MOD;
            current_hash = (current_hash * BASE + incoming) % MOD;
            hashes[current_hash]++;
        }
        return hashes;
    }
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        auto valid = [&](int k) {
            for (auto& p : rollingHash(nums, k)) if (p.second == 1) return true;
            return false;
        };
        int l=1, r=n, m, ans=n;
        while (l <= r) {
            m = (l + r) / 2;
            if (valid(m)) {
                ans = min(ans, m);
                r = m - 1;
            }
            else l = m + 1;
        }
        return ans;
    }
};
