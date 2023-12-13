class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int n = word.size();
        int ans = 0;
        for (int i=0; i<n-1; i++) {
            if (abs(word[i] - word[i+1]) <= 1) {
                word[i+1] = '\0';
                ans++;
            }
        }
        return ans;
    }
};
