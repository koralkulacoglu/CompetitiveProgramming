class Solution {
    void reverseNum(string& s) {
        int n = s.size();
        reverse(s.begin(), s.end());
        int idx = n-1;
        for (int i=0; i<n; i++) {
            if (s[i] != '0') {
                idx = i;
                break;
            }
        }
        s = s.substr(idx, n-idx);
    }
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<string, int> lastIdx;
        int ans = 1e9;
        for (int i=0; i<n; i++) {
            string s = to_string(nums[i]);
            if (lastIdx[s]) {
                int j = lastIdx[s] - 1;
                ans = min(ans, i - j);
            }

            // cout << s << ' ';
            reverseNum(s);
            // cout << s << endl;
            lastIdx[s] = i+1;
        }

        return (ans < 1e9 ? ans : -1);
    }
};
