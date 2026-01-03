class Solution {
public:
    set<long long> dp;
    bool comp=false;
    void precomp() {
        for (long long i=0; i<40; i++) {
            for (long long j=0; j<40; j++) {
                for (long long k=0; k<40; k++) {
                    if (pow(2, i) * pow(3, j) * pow(5, k) >= 1e10) continue;
                    dp.insert(pow(2, i) * pow(3, j) * pow(5, k));
                }
            }
        }
        comp = true;
    }
    
    int nthUglyNumber(int n) {
        if (!comp) precomp();
        return *next(dp.begin(), n-1);
    }
};
