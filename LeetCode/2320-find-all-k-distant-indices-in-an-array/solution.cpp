class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& a, int key, int k) {
        set<int> res;
        int n=a.size();
        for (int j=0; j<n; j++) {
            if (a[j] != key) continue;
            for (int i=max(0, j-k); i<min(n, j+k+1); i++) {
                res.insert(i);
            }
        }
        vector<int> fin;
         for (auto& i : res) {
            fin.push_back(i);
         }
        return fin;
    }
};
