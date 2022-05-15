class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& a) {
        sort(a.begin(), a.end());
        a.insert(a.begin(), bottom-1);
        a.push_back(top+1);
        int ans=0, n=a.size();
        for (int i=0; i<n-1; i++) {
            ans = max(ans, a[i+1]-a[i]-1);
        }
        return ans;
    }
};
