class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<bitset<26>> bits(n, 0);
        for (int i=0; i<n; i++) {
            for (char &j : words[i]) {
                bits[i][j-'a'] = true;
            }
        }
        int ans=0;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                if ((bits[i] & bits[j]).count() == 0) {
                    ans = max(ans, int(words[i].size() * words[j].size()));
                }
            }
        }
        return ans;
    }
};
