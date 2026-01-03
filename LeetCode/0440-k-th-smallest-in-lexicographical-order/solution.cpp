class Solution {
public:
    int count(int n, int x) {
        int cnt = 0;
        long long first = x;
        long long nxt = x+1;
        while (first <= n) {
            cnt += min((long long)n+1, nxt) - first;
            first *= 10;
            nxt *= 10;
        }

        return cnt;
    }

    int findKthNumber(int n, int k) {
        int cur = 1;
        k--;
        while (k > 0) {
            int cnt = count(n, cur);
            if (cnt <= k) {
                k -= cnt;
                cur++;
            }
            else {
                k--;
                cur *= 10;
            }
        }

        return cur;
    }
};
