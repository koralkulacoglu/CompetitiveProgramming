class Solution {
public:
    int maximumUniqueSubarray(vector<int>& a) {
        int n=a.size(), ans=0, sm=0;
        queue<int> loc;
        unordered_map<int, bool> seen;
        for (int i=0; i<n; i++) {
            sm += a[i];
            loc.push(a[i]);
            if (seen[a[i]]) {
                while (loc.front() != a[i]) {
                    sm -= loc.front();
                    seen[loc.front()] = false;
                    loc.pop();
                }
                seen[a[i]] = true;
                sm -= loc.front();
                loc.pop();
            }
            else {
                seen[a[i]] = true;
            }
            ans = max(ans, sm);
        }
        return ans;
    }
};
