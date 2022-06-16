class Solution {
public:
    string max(string& s1, string s2){
        return s1.size()>s2.size()?s1:s2;
    }
    
    string solve(string& s, int i, int j){
        while(i>=0 && j<s.size() && s[i] == s[j]){
            i--; j++;
        }
        return s.substr(i+1, j-i-1);
    }
    
    string longestPalindrome(string s) {
        string res = "";
        for(int i=0; i<s.size(); i++){
            res = max(res, solve(s, i-1, i+1));
            res = max(res, solve(s, i, i+1));
        }
        return res;
    }
};
