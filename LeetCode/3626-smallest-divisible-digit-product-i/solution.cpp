class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            long long digits = 1;
            int temp = n;
            while (temp) {
                digits *= temp % 10;
                temp /= 10;
            }
            if (digits % t == 0) return n;
            n++;
        }
        return -1;
    }
};
