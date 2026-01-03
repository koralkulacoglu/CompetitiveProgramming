class Solution {
public:
    string greatestLetter(string s) {
        unordered_map<char, bool> vis;
        int n=s.size();
        char ans=' ';
        for (char &i : s) {
            if (isupper(i) && vis[tolower(i)] && (i > ans)) {
                ans = i;
            }
            else if (islower(i) && vis[toupper(i)] && (toupper(i) > ans)) {
                ans = toupper(i);
            }
            vis[i] = true;
            // cout << ans << ' ';
        }
        return (string(1, ans)!=" ")?string(1, ans):"";
    }
};
