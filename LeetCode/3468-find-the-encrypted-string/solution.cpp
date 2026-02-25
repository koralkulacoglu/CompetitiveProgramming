class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n = s.size();
        string ns = s;
        for (int i=0; i<n; i++) ns[i] = s[(i+k)%n];
        return ns;
    }
};
