class Solution {
public:
    int maxDifference(string s) {
        vector<int> a(27, 0);
        for (char c : s) a[c - 'a']++;

        int max_odd = 0;
        int min_even = 1e9;
        for (int i : a) {
            if (i == 0) continue;

            if (i%2) max_odd = max(max_odd, i);
            else min_even = min(min_even, i);
        }

        return max_odd - min_even;
    }
};
