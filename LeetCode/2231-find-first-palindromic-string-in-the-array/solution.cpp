class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (string &i : words) {
            int n = i.size();
            bool wk = true;
            for (int j=0; j<n/2; j++) {
                if (i[j] != i[n-j-1]) {
                    wk = false;
                    break;
                }
            }
            if (wk) return i;
        }
        return "";
    }
};
