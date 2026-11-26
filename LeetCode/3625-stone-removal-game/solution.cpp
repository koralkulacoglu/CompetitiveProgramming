class Solution {
public:
    bool canAliceWin(int n) {
        int rem = 11;
        while (n >= 0) n -= --rem;
        return rem % 2;
    }
};
