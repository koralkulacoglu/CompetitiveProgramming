class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int n = arr.size();
        if (m > n) return false;

        auto checkPatterns = [&](int startIdx) -> bool {
            int endIdx = startIdx + m * k;
            vector<int> pattern(arr.begin() + startIdx, arr.begin() + startIdx + m);
            for (int i = startIdx; i < endIdx; i += m) {
                vector<int> curPattern(arr.begin() + i, arr.begin() + i + m);

                if (curPattern != pattern) return false;
            }

            return true;
        };

        for (int i{0}; i<n-m*k+1; i++) {
            if (checkPatterns(i)) return true;
        }

        return false;
    }
};
