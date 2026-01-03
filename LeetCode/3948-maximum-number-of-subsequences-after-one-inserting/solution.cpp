class Solution {
public:
    long long numOfSubsequences(string s) {
        const int n = s.size();

        /* ---------- prefix / suffix helpers ---------- */
        vector<long long> prefixL(n + 1, 0);      // # L in s[0 .. i-1]
        vector<long long> suffixT(n + 1, 0);      // # T in s[i .. n-1]
        vector<long long> prefixLC(n + 1, 0);     // # “LC” subseq in s[0 .. i-1]
        vector<long long> suffixCT(n + 1, 0);     // # “CT” subseq in s[i .. n-1]

        for (int i = 0; i < n; ++i)
            prefixL[i + 1] = prefixL[i] + (s[i] == 'L');

        for (int i = n - 1; i >= 0; --i)
            suffixT[i] = suffixT[i + 1] + (s[i] == 'T');

        long long Lcnt = 0, LCcnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'L') Lcnt++;
            else if (s[i] == 'C') LCcnt += Lcnt;         // every earlier L with this C
            prefixLC[i + 1] = LCcnt;
        }

        long long Tcnt = 0, CTcnt = 0;
        suffixCT[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == 'T') Tcnt++;
            else if (s[i] == 'C') CTcnt += Tcnt;         // this C with every later T
            suffixCT[i] = CTcnt;
        }

        /* ---------- existing “LCT” subsequences ---------- */
        long long totalExisting = 0, L_seen = 0, LC_seen = 0;
        for (char ch : s) {
            if (ch == 'L') ++L_seen;
            else if (ch == 'C') LC_seen += L_seen;
            else if (ch == 'T') totalExisting += LC_seen;
        }

        /* ---------- try every insertion position (0 … n) ---------- */
        long long best = totalExisting;
        for (int i = 0; i <= n; ++i) {
            // insert 'L'  → adds every “CT” starting at/after i
            best = max(best, totalExisting + suffixCT[i]);

            // insert 'T'  → adds every “LC” ending before i
            best = max(best, totalExisting + prefixLC[i]);

            // insert 'C'  → pairs every earlier L with every later T
            best = max(best, totalExisting + prefixL[i] * suffixT[i]);
        }

        return best;
    }
};

