class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string res;
        // Handle sign
        if ((numerator < 0) ^ (denominator < 0)) res.push_back('-');

        // Work in 64-bit to avoid overflow (e.g., INT_MIN)
        long long n = llabs((long long)numerator);
        long long d = llabs((long long)denominator);

        // Integer part
        long long integerPart = n / d;
        res += to_string(integerPart);

        long long rem = n % d;
        if (rem == 0) return res; // no fractional part

        res.push_back('.');

        // Map remainder -> index in result where this remainder first appeared
        unordered_map<long long, int> seen;
        while (rem != 0) {
            if (seen.count(rem)) {
                // Insert '(' at the position where this remainder first appeared
                res.insert(seen[rem], "(");
                res.push_back(')');
                break;
            }
            seen[rem] = (int)res.size();
            rem *= 10;
            long long digit = rem / d;
            res.push_back(char('0' + digit));
            rem %= d;
        }

        return res;
    }
};
