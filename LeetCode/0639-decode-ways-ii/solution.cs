public class Solution {
    public int NumDecodings(string s) {
        const int MOD = 1_000_000_007;
        int n = s.Length;

        // If the first character is '0', return 0 immediately as it's invalid
        if (s[0] == '0') return 0;

        long prev1 = s[0] == '*' ? 9 : 1;
        long prev2 = 1;

        for (int i = 1; i < n; i++) {
            long current = 0;

            if (s[i] == '0') {
                if (s[i - 1] == '1' || s[i - 1] == '2') {
                    current = prev2;
                } else if (s[i - 1] == '*') {
                    current = prev2 * 2;
                }
            } else if (s[i] == '*') {
                current = (prev1 * 9) % MOD;

                if (s[i - 1] == '1') {
                    current = (current + prev2 * 9) % MOD;
                } else if (s[i - 1] == '2') {
                    current = (current + prev2 * 6) % MOD;
                } else if (s[i - 1] == '*') {
                    current = (current + prev2 * 15) % MOD;
                }
            } else {
                current = prev1;

                if (s[i - 1] == '1') {
                    current = (current + prev2) % MOD;
                } else if (s[i - 1] == '2' && s[i] <= '6') {
                    current = (current + prev2) % MOD;
                } else if (s[i - 1] == '*') {
                    current = (current + (s[i] <= '6' ? prev2 * 2 : prev2)) % MOD;
                }
            }

            prev2 = prev1;
            prev1 = current;
        }

        return (int)prev1;
    }
}
