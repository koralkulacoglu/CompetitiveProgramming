vector<int> f(31, 0);

class Solution {
public:
    int fib(int n) {
        if (f[0] == 0) {
            f[0] = 0;
            f[1] = 1;
            for (int i=2; i<31; i++) {
                f[i] = f[i-1] + f[i-2];
            }
        }
        return f[n];
    }
};
