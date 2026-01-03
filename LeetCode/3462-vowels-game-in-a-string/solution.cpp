/*

who can take the whole thing?

*/

class Solution {
public:
    bool doesAliceWin(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        
        for (char c : s) {
            if (vowels.find(c) != vowels.end()) {
                return true;
            }
        }
        
        return false;
    }
};
