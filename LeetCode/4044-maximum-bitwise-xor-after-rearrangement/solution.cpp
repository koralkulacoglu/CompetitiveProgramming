class Solution {
public:
    string maximumXor(string s, string t) {
        int zeros=0, ones=0;
        for (char c : t) {
            zeros += c == '0';
            ones += c == '1';
        }

        string res;
        for (char c : s) {
            if (c == '1') {
                if (zeros) {
                    res += '1';
                    zeros--;
                }
                else {
                    res += '0';
                    ones--;
                }
            }
            else {
                if (ones) {
                    res += '1';
                    ones--;
                }
                else {
                    res += '0';
                    zeros--;
                }
            }
        }

        return res;
    }
};
