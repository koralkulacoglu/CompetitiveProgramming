class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0) return 0;

        map<char, int> freq;
        freq[s[0]] = 1;
        
        int ans = 1;
        int left = 0;
        for (int right=1; right<n; right++) {
            if (freq[s[right]]) {
                while (s[left] != s[right]) {
                    freq[s[left]]--;
                    left++;
                }
                left++;
            }
            else {
                freq[s[right]]++;
            }
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
