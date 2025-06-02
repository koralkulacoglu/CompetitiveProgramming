class Solution {
public:
    bool good(vector<int>& a) {
        return a[0] && a[1] && a[2];
    }

    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        int left = 0;
        vector<int> a(3, 0);
        for (int i=0; i<n; i++) {
            a[s[i] - 'a']++;
            while (good(a)) {
                ans += n-i;
                a[s[left] - 'a']--;
                left++;
            }
        }

        return ans;
    }
};
