class Solution {
public:
    bool noZero(int x) {
        string s = to_string(x);
        for (char c : s) {
            if (c == '0') return false;
        }
        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        for (int i=1; i<n; i++) {
            if (noZero(i) && noZero(n-i)) return {i, n-i};
        }
        return {-1, -1};
    }
};
