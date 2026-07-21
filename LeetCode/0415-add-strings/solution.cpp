class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int n = num1.size();
        int m = num2.size();

        bool carry{false};
        string res;
        for (int i=0; i<max(n, m); i++) {
            int n1 = (i < n ? num1[i] - '0' : 0);
            int n2 = (i < m ? num2[i] - '0' : 0);

            int s = n1 + n2 + carry;
            carry = s >= 10;
            s -= carry * 10;

            res.push_back('0' + s);
        }

        if (carry) res.push_back('1');

        reverse(res.begin(), res.end());

        return res;
    }
};
