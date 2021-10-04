class Solution {
public:
    bool isPalindrome(int m) {
        string n = to_string(m);
        int s = n.length();

        for (int i=0;i<floor(s/2); i++){
            if (n[i] != n[s-i-1]) {
                return false;
            }
        }
        return true;
    }
};
