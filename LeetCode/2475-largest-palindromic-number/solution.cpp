class Solution {
public:
    string largestPalindromic(string num) {
        sort(num.begin(), num.end(), greater<char>());
        string left, right;
        string middle = "";
        int n = num.size();
        for (int i=0; i<n; i++) {
            if (i<n-1 && num[i] == num[i+1]) {
                left += num[i];
                right += num[i+1];
                i++;
            }
            else if (!middle.size()) {
                middle = num[i];
            }
        }
        reverse(right.begin(), right.end());
        string res = left + middle + right;

        bool zr = true;
        for (char i : res) {
            if (i != '0') {
                zr = false;
                break;
            }
        }
        if (zr) return "0";
        
        int idx = 0;
        for (int i=0; i<res.size(); i++) {
            if (res[i] == '0') {
                idx = i+1;
            }
            else {
                break;
            }
        }

        int end = res.size()-idx;
        string ans = "";
        for (int i=idx; i<end; i++) {
            ans += res[i];
        }
        return ans;
    }
};
