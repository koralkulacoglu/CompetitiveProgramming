class Solution {
    std::string intToBinaryString(int num, size_t n) {
        bitset<32> bits(num);
        string binaryString = bits.to_string();
        return binaryString.substr(binaryString.length() - n);
    }

    vector<string> generateStrings(int n) {
        vector<string> res;
        for (int i=0; i<pow(2, 2*n); i++) {
            string cur = intToBinaryString(i, 2*n);
            replace(cur.begin(), cur.end(), '0', '(');
            replace(cur.begin(), cur.end(), '1', ')');
            res.push_back(cur);
        }
        return res;
    }

    bool isValid(string s) {
        int open = 0;
        for (char c : s) {
            if (c == ')') {
                if (open == 0) return false;
                open--;
            }
            else {
                open++;
            }
        }

        return open > 0 ? false : true;
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> all = generateStrings(n);
        vector<string> valid;

        for (string s : all) {
            if (isValid(s)) valid.push_back(s);
        }
        
        return valid;
    }
};
