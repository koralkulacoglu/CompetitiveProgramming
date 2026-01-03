class Solution {
public:
    int partitionString(string s) {
        int ans = 1;
        map<char, bool> seen;
        for (char i : s) {
            if (seen[i]) {
                seen.clear();
                ans++;
            }
            seen[i] = true;
        }
        return ans;
    }
};
