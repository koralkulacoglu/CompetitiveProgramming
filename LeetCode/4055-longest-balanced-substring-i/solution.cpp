class Solution {
    bool isValid(vector<int>& f) {
        int val = -1;
        for (int i : f) {
            if (i == 0) continue;
            if (val != -1 && val != i) return false;
            val = i;
        }
        return true;
    }

public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;
        for (int i=0; i<n; i++) {
            vector<int> freq(26, 0);
            for (int j=i; j<n; j++) {
                freq[s[j]-'a']++;
                if (isValid(freq)) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};
