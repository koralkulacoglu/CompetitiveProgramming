class Solution {
public:
    int countCommas(int n) {
        auto commas = [](int x) {
            string s = to_string(x);
            return (s.size() - 1) / 3;
        };
        
        int ans = 0;
        for (int i=1; i<=n; i++) {
            ans += commas(i);
        }

        return ans;
    }
};
