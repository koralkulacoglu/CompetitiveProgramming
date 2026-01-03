class Solution {
public:
    int checkPalindromeB(int N, int B)
    {
        // Stores the reverse of N
        int rev = 0;

        // Stores the value of N
        int N1 = N;

        // Extract all the digits of N
        while (N1) {
            // Generate its reverse
            rev = rev * B + N1 % B;
            N1 = N1 / B;
        }

        return N == rev;
    }

    bool isStrictlyPalindromic(int n) {
        for (int i=2; i<=n-2; i++) {
            if (!checkPalindromeB(n, i)) return false;
        }
        return true;
    }
};
