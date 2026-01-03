class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int n=list1.size(), m=list2.size();
        unordered_map<string, int> like;
        for (int i=0; i<m; i++) {
            if(!like[list2[i]]) like[list2[i]] = i+1;
        }
        
        int ans=1e9;
        vector<string> res;
        for (int i=0; i<n; i++) {
            if (like[list1[i]] && i+1 + like[list1[i]] < ans) {
                ans = i+1 + like[list1[i]];
                res = {list1[i]};
            }
            else if (like[list1[i]] && i+1 + like[list1[i]] == ans) {
                res.push_back(list1[i]);
            }
        }
        return res;
    }
};
