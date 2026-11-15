/*

o + o = e
e + o = o
o + e = o
e + e = e

*/

class Solution {
    static constexpr int MOD = 1e9 + 7;
public:
    int numOfSubarrays(vector<int>& arr) {
        int e=1, o=0, psa=0, ans=0;
        for (int i : arr) {
            psa += i;
            psa %= 2;
            if (psa%2) {
                o++;
                ans += e;
            }
            else {
                e++;
                ans += o;
            }
            ans %= MOD;
        }
        return ans;
    }
};
