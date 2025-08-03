class Solution {
public:
    int chalkReplacer(vector<int>& chalk, long long k) {
        int n = chalk.size();
        long long total = accumulate(chalk.begin(), chalk.end(), 0LL);
        k %= total;

        for (int i=0; i<n; i++) {
            k -= chalk[i];
            if (k < 0) return i;
        }

        return n-1;
    }
};
