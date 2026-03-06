class Solution {
public:
    bool checkOnesSegment(string s) {
        bool one = false;
        bool zero = false;
        for (char c : s) {
            if (zero && c == '1') return false;
            if (one && c == '0') zero = true;
            if (c == '1') one = true;
        }
        return one;
    }
};
