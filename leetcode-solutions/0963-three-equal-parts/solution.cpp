#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int n = arr.size();
        int ones = 0;
        for (int b : arr) ones += b;

        // Case: all zeros -> any split into non-empty parts works
        if (ones == 0) return {0, n - 1};

        // Must split ones into 3 equal groups
        if (ones % 3 != 0) return {-1, -1};
        int k = ones / 3;

        // Find the start index of each part (first '1' of each segment)
        int first = -1, second = -1, third = -1;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] == 1) {
                cnt++;
                if (cnt == 1) first = i;
                else if (cnt == k + 1) second = i;
                else if (cnt == 2 * k + 1) third = i;
            }
        }

        // Now the pattern starting at first, second, third must be identical.
        // Walk them together while they match.
        int i = first, j = second, k3 = third;
        while (k3 < n) {
            if (arr[i] != arr[j] || arr[i] != arr[k3]) return {-1, -1};
            i++; j++; k3++;
        }

        // At this point, the suffix length from 'third' to end dictates how many zeros
        // the first two parts must be allowed to include to align boundaries.
        int lenSuffix = n - third; // length of the common pattern (ending at n)
        int iEnd = i - 1;          // last index of the pattern in part1 (before padding zeros)
        int jEnd = j - 1;          // last index of the pattern in part2

        // We need to place cuts so that:
        // [0..iCut] is part1, [iCut+1..jCut-1] is part2, [jCut..n-1] is part3
        // and the tail zeros after the pattern in part1/part2 match the tail zeros in part3.
        // The earliest valid cuts:
        int iCut = first + (lenSuffix - 1);   // end of pattern segment 1
        int jCut = second + (lenSuffix);      // start index of part3 (jCut) = end of part2 + 1

        // But we must ensure there are enough zeros between segments:
        // The number of zeros between iCut and second must be >= zeros needed to align.
        // Concretely, verify that:
        // - The segment [first, first+lenSuffix-1] equals [second, second+lenSuffix-1] equals [third, n-1]
        // - And we can end part1 at iCut and start part3 at jCut without breaking non-empty rule.
        // We already matched equality via the while loop; now just compute the concrete cuts.

        // iCut is the end of part1
        iCut = first + (lenSuffix - 1);
        // jCut is the start index of part3, so jCut = (second + lenSuffix)
        jCut = second + (lenSuffix);

        // Check bounds and non-empty condition arr[0..iCut], arr[iCut+1..jCut-1], arr[jCut..n-1]
        if (iCut + 1 < jCut && jCut <= n - 1) {
            return {iCut, jCut};
        }

        // If simple placement fails (rare due to leading/trailing zeros), try padding zeros count explicitly:
        // Count trailing zeros in the array after the last '1'
        int trailingZeros = 0;
        for (int t = n - 1; t >= 0 && arr[t] == 0; --t) trailingZeros++;

        // We need at least 'trailingZeros' zeros after the pattern in part1 and part2
        int end1 = first + (lenSuffix - 1) + trailingZeros;
        int end2 = second + (lenSuffix - 1) + trailingZeros + 1; // j index is end2 + 1

        if (end1 < second && end2 <= third) {
            // Cuts: [0..end1], [end1+1..end2-1], [end2..n-1]
            return {end1, end2};
        }

        return {-1, -1};
    }
};

