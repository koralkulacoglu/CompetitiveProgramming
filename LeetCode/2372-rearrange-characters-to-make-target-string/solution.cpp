class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> freq, freq2;
        for (char &i : s) freq[i]++;
        for (char &i : target) freq2[i]++;
        int mn=1e9;
        for (auto i : freq2) {
            mn = min(mn, freq[i.first]/i.second);
        }
        return mn;
    }
};
