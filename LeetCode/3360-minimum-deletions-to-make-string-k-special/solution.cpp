class Solution {
public:
    int minimumDeletions(string word, int k) {
        // Count frequencies of all characters (works for any charset).
        unordered_map<char,int> mp;
        for (char c : word) mp[c]++;

        // Collect frequencies.
        vector<int> freq;
        freq.reserve(mp.size());
        int maxf = 0;
        for (auto &p : mp) {
            freq.push_back(p.second);
            maxf = max(maxf, p.second);
        }

        // Early out: already k-special
        int mnf = *min_element(freq.begin(), freq.end());
        if (maxf - mnf <= k) return 0;

        // Try all possible lower bounds t in [0, maxf]
        long long ans = word.size(); // upper bound: delete everything
        for (int t = 0; t <= maxf; ++t) {
            long long del = 0;
            int upper = t + k;
            for (int f : freq) {
                if (f < t) del += f;                   // remove this char entirely
                else if (f > upper) del += (f - upper); // trim down to upper
                // else keep as is
                if (del >= ans) break; // small pruning
            }
            ans = min(ans, del);
        }
        return (int)ans;
    }
};
