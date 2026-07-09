class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        auto noZero = [](int x) -> bool {
            while (x) {
                if (x % 10 == 0) return false;
                x /= 10;
            }
            return true;
        };

        for (int i=1; i<n; i++) {
            if (noZero(i) && noZero(n - i)) return {i, n-i};
        }

        return {-1, -1};
    }
};
