class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (string i : words) {
            bool wk = true;
            for (int j=0; j<i.size()/2; j++) {
                if (i[j] != i[i.size()-j-1]) {
                    wk = false;
                    break;
                }
            }
            if (wk) return i;
        }
        return "";
    }
};
