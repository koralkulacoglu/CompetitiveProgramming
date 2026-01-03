class Solution {
public:
    char repeatedCharacter(string s) {
        map<char, bool> seen;
        for (char i : s) {
            if (seen[i]) return i;
            seen[i] = true;
        }
        return 'a';
    }
};
