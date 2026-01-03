class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), 
        [](vector<int>& p0, vector<int>& p1){
            return p0[1]<p1[1];
        });
    //    for(auto p: pairs) cout<<"("<<p[0]<<","<<p[1]<<")";
     
        int ans=0;
        int prev_r=INT_MIN;
        for (auto& p: pairs){
            if (p[0]> prev_r) {
                ans++;
                prev_r=p[1];
            }     
        }
        return ans;
    }
};
