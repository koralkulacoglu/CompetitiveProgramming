vector<string> conv = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

string calc(string s) {
    string res = "";
    for (char &i : s) res += conv[i-'a'];
    return res;
}

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_map<string, bool> seen;
        for (string &i : words) seen[calc(i)] = true;
        return seen.size();
    }
};



