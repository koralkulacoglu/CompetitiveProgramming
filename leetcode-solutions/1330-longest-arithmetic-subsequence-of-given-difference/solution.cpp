class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();

        int ans = 0;
        unordered_map<int, int> subseqLen;
        for (int i=0; i<n; i++) {
            int cur = arr[i];
            int prev = cur - difference;
            int len = subseqLen[prev] + 1;
            subseqLen[cur] = len;

            ans = max(ans, len);
        }

        return ans;
    }
};
