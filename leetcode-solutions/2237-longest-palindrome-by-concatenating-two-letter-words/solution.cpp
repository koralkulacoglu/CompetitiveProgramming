class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();

        multiset<string> ms;

        for (string s : words) ms.insert(s);

        bool middle = false;
        int ans = 0;
        for (string s : words) {
            string rs = s;
            reverse(rs.begin(), rs.end());

            auto ptr1 = ms.find(s);
            if (ptr1 == ms.end()) continue;
            ms.erase(ptr1);

            auto ptr2 = ms.find(rs);
            if (ptr2 != ms.end()) {
                ans += s.size() * 2;
                ms.erase(ptr2);
            }
            else if (s[0] == s[1]) middle = true;
        }

        return ans + middle * 2;
    }
};
