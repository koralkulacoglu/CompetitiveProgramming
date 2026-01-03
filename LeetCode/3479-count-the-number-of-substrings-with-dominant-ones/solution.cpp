class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = (int)s.size();
        std::vector<int> zeros;
        zeros.reserve(n);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') zeros.push_back(i);
        }
        int m = (int)zeros.size();
        long long ans = 0;

        // 1) Substrings with zero zeros (all ones) — always dominant
        for (int i = 0; i < n;) {
            if (s[i] == '1') {
                int j = i;
                while (j < n && s[j] == '1') ++j;
                long long L = j - i;
                ans += L * (L + 1) / 2;
                i = j;
            } else {
                ++i;
            }
        }

        // 2) Substrings with k >= 1 zeros and ones >= k^2
        const int B = 200; // sqrt(4e4)
        for (int k = 1; k <= std::min(B, m); ++k) {
            long long minLen = 1LL * k * k + k; // length >= k^2 + k
            if (minLen > n) break;

            // Consider each block of k consecutive zeros: zeros[idx .. idx+k-1]
            for (int idx = 0; idx + k - 1 < m; ++idx) {
                int prev = (idx == 0 ? -1 : zeros[idx - 1]);
                int nxt  = (idx + k - 1 == m - 1 ? n : zeros[idx + k]);

                // Valid starts a: [a_min, a_max]
                int a_min = prev + 1;
                int a_max = zeros[idx];

                // Valid ends b: [b_min, b_max]
                int b_min = zeros[idx + k - 1];
                int b_max = nxt - 1;

                if (a_min > a_max || b_min > b_max) continue;

                // Count pairs (a,b) with:
                //   a_min <= a <= a_max
                //   b_min <= b <= b_max
                //   b - a + 1 >= minLen  <=>  b >= a + minLen - 1

                // Case 1: a where a + minLen - 1 <= b_min
                // then the constraint is just b >= b_min, so any b in [b_min, b_max] works.
                long long x1 = (long long)b_min - minLen + 1; // max a s.t. a + minLen - 1 <= b_min
                if (x1 >= a_min) {
                    long long hi1 = std::min((long long)a_max, x1);
                    if (hi1 >= a_min) {
                        long long cnt_a = hi1 - a_min + 1;
                        long long cnt_b = (long long)b_max - b_min + 1;
                        if (cnt_b > 0) ans += cnt_a * cnt_b;
                    }
                }

                // Case 2: a where a + minLen - 1 > b_min
                // then b must be in [a + minLen - 1, b_max]
                long long low2  = std::max((long long)a_min,
                                           (long long)b_min - minLen + 2);
                long long high2 = std::min((long long)a_max,
                                           (long long)b_max - minLen + 1);
                if (high2 >= low2) {
                    long long cnt_a = high2 - low2 + 1;
                    long long c = (long long)b_max - minLen + 2;
                    // sum_{a=low2..high2} (b_max - (a + minLen - 1) + 1)
                    // = sum_{a=low2..high2} (c - a)
                    long long total = cnt_a * c
                                      - (low2 + high2) * cnt_a / 2;
                    ans += total;
                }
            }
        }

        return (int)ans;
    }
};

