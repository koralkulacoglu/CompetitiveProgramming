bool same(string a, string b) {
    vector<int> f1(26, 0), f2(26, 0);
    for (char &i : a) f1[i-'a']++;
    for (char &i : b) f2[i-'a']++;
    for (int i=0; i<26; i++) {
        if (f1[i] != f2[i]) return false;
    }
    return true;
}

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n=words.size();
        int i=n-1;
        while (i) {
            if (same(words[i], words[i-1])) {
                words.erase(words.begin() + i);
            }
            i--;
        }
        return words;
    }
};
