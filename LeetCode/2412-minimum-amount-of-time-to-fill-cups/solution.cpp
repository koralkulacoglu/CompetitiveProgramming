class Solution {
public:
    int fillCups(vector<int>& a) {
        int ans=0;
        while (accumulate(a.begin(), a.end(), 0) > 0) {
            sort(a.begin(), a.end(), greater<int>());
            a[0]--;
            a[1]--;
            a[1] = max(0, a[1]);
            ans++;
        }
        return ans;
    }
};
