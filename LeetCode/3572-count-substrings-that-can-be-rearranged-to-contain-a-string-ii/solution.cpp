class Solution {
public:
    bool valid(vector<int>& f1, vector<int>& f2) {
        for (int i=0; i<26; i++) {
            if (f1[i] < f2[i]) return false;
        }
        return true;
    }

    long long validSubstringCount(string word1, string word2) {
        int n = word1.size();
        vector<int> freq1(26, 0), freq2(26, 0);
        for (char c : word2) freq2[c-'a']++;

        long long ans = 0;
        int left = 0;
        for (int right=0; right<n; right++) {
            char r = word1[right];
            freq1[r-'a']++;

            while (valid(freq1, freq2)) {
                ans += n - right;
                char l = word1[left];
                freq1[l-'a']--;
                left++;
            }
        }

        return ans;
    }
};
