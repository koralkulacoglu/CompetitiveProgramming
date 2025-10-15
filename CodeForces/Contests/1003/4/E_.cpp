#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc; 
    if (!(cin >> tc)) return 0;
    while (tc--) {
        long long n, m, k;
        cin >> n >> m >> k;

        // Feasibility check
        if (k < llabs(n - m) || k > max(n, m)) {
            cout << -1 << '\n';
            continue;
        }

        bool flipped = false;
        // Ensure n >= m by swapping roles if needed.
        // We'll treat '0' as +1 and '1' as -1 with counts (n zeros, m ones).
        if (n < m) {
            swap(n, m);
            flipped = true;
        }

        long long T = n - m;            // final D
        long long a = min(m, k - T);    // initial dip size (# of leading 1's)
        long long b = k - a;            // peak after step 2

        string s;
        s.reserve(n + m);

        // Step 1: a ones
        s.append(a, '1');

        // Step 2: k zeros
        s.append(k, '0');

        // Step 3: (b - T) ones
        s.append(b - T, '1');

        // Remaining counts
        long long rem0 = n - k;
        long long rem1 = m - a - (b - T);
        // They should be equal now
        // rem0 == rem1 == n - k

        // Current level is T now. If T == b, start with '1' to not exceed max.
        bool startWithZero = (T < b);

        while (rem0 > 0 || rem1 > 0) {
            if (startWithZero) {
                if (rem0 > 0) { s.push_back('0'); --rem0; }
                if (rem1 > 0) { s.push_back('1'); --rem1; }
            } else {
                if (rem1 > 0) { s.push_back('1'); --rem1; }
                if (rem0 > 0) { s.push_back('0'); --rem0; }
            }
        }

        if (flipped) {
            for (char &c : s) c = (c == '0' ? '1' : '0');
        }

        cout << s << '\n';
    }
    return 0;
}

