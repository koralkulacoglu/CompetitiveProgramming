class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for (vector<int> i : queries) {
            long long l = i[0];
            long long r = i[1];
            long long ops = 0;
            for (long long i=0; i<18; i++) {
                long long curPow = pow(4, i);
                long long nextPow = pow(4, i+1) - 1;
                long long nums = max(0LL, min(r, nextPow) - max(l, curPow) + 1);
                ops += (i+1) * nums;
            }
            ans += (ops + 1) / 2;
        }
        return ans;
    }
};
