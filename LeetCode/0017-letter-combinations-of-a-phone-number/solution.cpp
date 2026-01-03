class Solution {
public:
    map<char, string> phone;

    Solution() {
        phone['2'] = "abc";
        phone['3'] = "def";
        phone['4'] = "ghi";
        phone['5'] = "jkl";
        phone['6'] = "mno";
        phone['7'] = "pqrs";
        phone['8'] = "tuv";
        phone['9'] = "wxyz";
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;
        
        for (char i : phone[digits[0]]) {
            vector<string> combs = letterCombinations(digits.substr(1));
            if (combs.empty()) res.push_back(string(1, i));
            else {
                for (string s : combs) {
                    res.push_back(i + s);
                }
            }
        }
        return res;
    }
};
