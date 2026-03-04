class Solution {
public:
    string trimTrailingVowels(string s) {
        string res;
        bool trail = true;
        int n = s.size();
        for (int i=n-1; i>=0; i--) {
            if (!(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')) {
                trail = false;
            }
            if (!trail) res.push_back(s[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
