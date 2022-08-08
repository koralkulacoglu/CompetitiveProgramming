class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char, int> freq1, freq2;
        for (char i : s) freq1[i]++;
        for (char i : t) freq2[i]++;
        for (int i=0; i<26; i++) {
            if (freq1['a'+i] != freq2['a'+i]) {
                return 'a'+i;
            }
        }
        return 'a';
    }
};
