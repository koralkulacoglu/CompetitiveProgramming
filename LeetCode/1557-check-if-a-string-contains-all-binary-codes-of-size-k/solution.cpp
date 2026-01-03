class Solution {
public:
    /*
    bool hasAllCodes(string s, int k) {
        if (k > s.size()) return false;
        unordered_map<string, bool> seen;
        string val = s.substr(0, k);
        seen[val] = true;
        int n=s.size(), ans=1;
        for (int i=k; i<n; i++) {
            val.erase(0, 1);
            val += s[i];
            if (seen[val]) continue;
            seen[val] = true;
            ans++;
        }
        // cout << ans;
        return ans == pow(2, k);
    }
    */
    bool hasAllCodes(string s, int k) {

        //Edge case
        if(k > s.size()) return false;

        unordered_set<string> res_set;

        //Insertion into the set
        for(int i =0;i<= s.size()-k;i++)
            res_set.insert(s.substr(i,k));

        //Comparing res with 2^k
        return res_set.size() == pow(2,k);
    }

};
