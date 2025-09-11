class Solution {
public:
    bool isVowel(char c) {
        if (c == 'a') return true;
        if (c == 'e') return true;
        if (c == 'i') return true;
        if (c == 'o') return true;
        if (c == 'u') return true;
        if (c == 'A') return true;
        if (c == 'E') return true;
        if (c == 'I') return true;
        if (c == 'O') return true;
        if (c == 'U') return true;
        return false;
    }

    string sortVowels(string s) {
        int n = s.size();

        vector<char> vowels;
        for (char c : s) {
            if (isVowel(c)) vowels.push_back(c);
        }

        sort(vowels.begin(), vowels.end(), greater<char>());

        for (int i=0; i<n; i++) {
            if (isVowel(s[i])) {
                s[i] = vowels.back();
                vowels.pop_back();
            }
        }

        return s;
    }
};
