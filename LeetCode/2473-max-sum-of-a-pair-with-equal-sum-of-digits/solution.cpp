class Solution {
public:
    int count(int i) {
        string res = to_string(i);
        int cnt=0;
        for (char i : res) {
            cnt += i-'0';
        }
        return cnt;
    }
    
    int maximumSum(vector<int>& nums) {
        int ans=-1;
        map<int, int> digits;
        for (int &i : nums) {
            int cnt = count(i);
            if (digits[cnt]) {
                ans = max(ans, i + digits[cnt]);
            }
            digits[cnt] = max(digits[cnt], i);
            // cout << cnt << ' ';
        }
        return ans;
    }
};
