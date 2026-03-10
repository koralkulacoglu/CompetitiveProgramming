class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_map<string, bool> appear;
        for (string s : nums) appear[s] = true;
        for (int i=0; i<pow(2, n); i++) {
            string s(n, '0');
            for (int j=0; j<n; j++) {
                if ((i >> j) & 1) s[j] = '1';
            }
            if (!appear[s]) return s;
        }
        return "";
    }
};
