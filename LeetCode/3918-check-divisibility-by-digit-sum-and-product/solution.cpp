class Solution {
public:
    bool checkDivisibility(int n) {
        bool has0 = false;
        int sum = 0;
        int temp = n;
        while (temp) {
            sum += temp % 10;
            if (temp % 10 == 0) has0 = true;
            temp /= 10;
            if (sum > n) return false;
        }
        if (has0) {
            return n % sum == 0;
        }

        int prod = 1;
        temp = n;
        while (temp) {
            prod *= temp % 10;
            temp /= 10;
            if (sum + prod > n) return false;
        }
        return n % (sum + prod) == 0;
    }
};
